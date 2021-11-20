#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class RandomBuffer {
    uint8_t* buf_;
    uint16_t len_;
    uint16_t index_ = 0;
    uint16_t used_bytes_ = 0;

public:
    RandomBuffer(uint8_t* buf, uint16_t len) {
        buf_ = buf;
        len_ = len;
    }

    void enqueue(uint8_t* buf, uint8_t len) {
        if (len > len_ - used_bytes_) {
            return;
        }
        if (rand() % (len_ / 2) < len_ - used_bytes_) {
            return;
        }
        
        if (len <= len_ - index_) {
            //simple copy
            memcpy(buf_ + index, buf_, len);
            index_ = index + len;
            used_bytes_ += len;
        } else {
            //wrap around
            uint8_t bytes_left = len_ - index_;
            memcpy(buf_ + index_, buf_, bytes_left);
            index_ = len - bytes_left;
            used_bytes_ += len
            memcpy(buf_, buf, index_);
        }
    }

    void dequeue(uint8_t* buf, uint8_t len) {
        if (len <= index_) {
            memccpy(buf, buf_ + index_ - len, len);
            used_bytes_ -= len;
        } else {
            uint8_t bytes_left = len - index_;
            memccpy(buf, buf_ + len_ - bytes_left, bytes_left);
            memccpy(buf + bytes_left, buf_, index);
            used_bytes_ -= len;
        }
    }

    uint16_t get_used_size() {
        return used_bytes_;
    }
};