#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class RandomBuffer {
public:
    uint8_t* buf_;
    uint16_t len_;
    uint16_t insert_index_ = 0;
    uint16_t output_index_ = 0;
    uint16_t used_bytes_ = 0;

//public:
    RandomBuffer(uint8_t* buf, uint16_t len) {
        buf_ = buf;
        len_ = len;
    }

    bool enqueue(uint8_t* buf, uint16_t len, uint8_t force = 0) {
        if (len > len_ - used_bytes_) {
            return false;
        }
        if (rand() % (len_ / 2) > len_ - used_bytes_ && !force) {
            return false;
        }
        
        if (len <= len_ - insert_index_) {
            //simple copy
            memcpy(buf_ + insert_index_, buf, len);
            insert_index_ = insert_index_ + len;
            used_bytes_ += len;
        } else {
            //wrap around
            uint16_t bytes_left = len_ - insert_index_;
            memcpy(buf_ + insert_index_, buf, bytes_left);
            insert_index_ = len - bytes_left;
            used_bytes_ += len;
            memcpy(buf_, buf + bytes_left, insert_index_);
        }
        return true;
    }

    void dequeue(uint8_t* buf, uint16_t len) {
        if (len_ < output_index_ + len) {
            uint16_t bytes_left = len_ - output_index_;
            memcpy(buf, buf_ + output_index_, bytes_left);
            output_index_ = len - bytes_left;
            memcpy(buf + bytes_left, buf_, output_index_);
            used_bytes_ -= len;
        } else {
            memcpy(buf, buf_ + output_index_, len);
            output_index_ += len;
            used_bytes_ -= len;
        }
    }

    uint16_t get_used_size() {
        return used_bytes_;
    }
};