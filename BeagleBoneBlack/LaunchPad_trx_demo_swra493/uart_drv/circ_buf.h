/*
 * circ_buf.h
 *
 *  Created on: Jan 19, 2015
 *      Author: a0869488
 */

#ifndef CIRC_BUF_H_
#define CIRC_BUF_H_

typedef struct {
	unsigned int head_ptr;
	unsigned int tail_ptr;
	unsigned int size_of_buffer;
	char *buffer;
} circ_buffer_t;


void circ_buf_init(circ_buffer_t *buffer, char *data_buffer, unsigned int length);
unsigned int circ_buf_remainder(circ_buffer_t *buffer);
void circ_buf_put_data(circ_buffer_t *buffer, unsigned char data);
unsigned char circ_buf_get_data(circ_buffer_t *buffer);

#endif /* CIRC_BUF_H_ */
