#define MAX_MESSAGES_LEN (16)
#define BUF_LEN (2048)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Spool {
protected:
	// len1 message1 len2 message2...
	uint8_t buf [BUF_LEN];
	uint16_t start_index = 0;
	uint16_t end_index = 0;
	uint16_t nb_messages = 0;

public:
	Spool() {
	}

	bool append(uint8_t* message, uint16_t message_len) {
		if (message_len > MAX_MESSAGES_LEN) {
			return false;
		}

		if (((this->end_index < this->start_index)
				and (this->end_index + message_len + 1 > this->start_index))
			or
			((this->end_index >= this->start_index)
				and this->end_index + message_len + 1 - BUF_LEN > this->start_index))
		{
			return false;
		}

		// Length insertion
		this->buf[this->end_index] = (uint8_t)message_len;
		this->end_index = (this->end_index + 1) % BUF_LEN;


		if (BUF_LEN - this->end_index >= message_len) {
			memcpy(this->buf + this->end_index, message, message_len);
		}
		else {
			memcpy(this->buf + this->end_index, message, BUF_LEN - this->end_index);
			memcpy(this->buf, message + BUF_LEN - this->end_index, message_len - BUF_LEN + this->end_index);
			
		}
		this->end_index = (this->end_index + message_len) % BUF_LEN;
		this->nb_messages += 1;
		return true;
	}

	uint16_t pop(uint16_t can_send, uint8_t* out_buf) {
		// Pop the n first messages
		uint16_t len;
		uint16_t should_send = 0;

		len = (uint16_t)this->buf[this->start_index];
		while (should_send + len <= can_send and this->start_index != this->end_index)
		{
			this->start_index = (this->start_index + 1) % BUF_LEN;
			if (this->start_index + len <= BUF_LEN) {
				memcpy(out_buf + should_send, this->buf + this->start_index, len);
			}
			else {
				memcpy(out_buf + should_send, this->buf + this->start_index, BUF_LEN - this->start_index);
				memcpy(out_buf + should_send + BUF_LEN - this->start_index, this->buf, len - BUF_LEN + this->start_index);
			}
			this->start_index = (this->start_index + len) % BUF_LEN;
			this->nb_messages -= 1;
			should_send += len;
			len = (uint16_t)this->buf[this->start_index];
		}
		return should_send;
	}

	uint16_t getLength() {
		if (this->end_index < this->start_index) {
			return BUF_LEN - this->start_index + this->end_index;
		}
		else {
			return this->end_index - this->start_index;
		}
	}

	uint16_t getNbMessages() {
		return this->nb_messages;
	}

	void print() {
		if (this->end_index == 0) {printf("!");}
		for (int i = 0; i < BUF_LEN; ++i)
		{
			if (this->start_index == i) {printf("!");}
			printf("%d ", this->buf[i]);
			if (this->end_index == i+1) {printf("!");}
		}
		printf("\n");
	}
};
