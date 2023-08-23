/*
 * Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include "circ_buf.h"

/**************************************************************************
 * @brief unsigned char circ_buf_init(circ_buffer_t data)
 *
 * Initialize the circular buffer container
 *
 * @param   circ_buffer_t *buffer   pointer to circular buffer structure
 *          char data_buffer        pointer to actual storage location
 *          unsigned char length    length of actual storage array
 *
 * @return none
 **************************************************************************/
void circ_buf_init(circ_buffer_t *buffer, char *data_buffer, unsigned int length) {

	buffer->buffer = data_buffer;
	buffer->head_ptr = 0;
	buffer->tail_ptr = 0;
	buffer->size_of_buffer = length;

	return;
}

/**************************************************************************
 * @brief unsigned char circ_buf_remainder(circ_buffer_t data)
 *
 * Find the remaining space left in the circular buffer
 *
 * @param  none
 *
 * @return number of bytes remaining in the buffer
 **************************************************************************/
unsigned int circ_buf_remainder(circ_buffer_t *buffer) {
	unsigned int ret;

	if(buffer->head_ptr >= buffer->tail_ptr) {
		ret = buffer->size_of_buffer - (buffer->head_ptr - buffer->tail_ptr);
	} else {
		ret = (buffer->tail_ptr - buffer->head_ptr);
	}
	return ret;
}

/**************************************************************************
 * @brief  void circ_buf_put_data(circ_buffer_t *buffer, unsigned char data)
 *
 * Add a char the circular buffer
 *
 * @param  none
 *
 * @return none
 **************************************************************************/
void circ_buf_put_data(circ_buffer_t *buffer, unsigned char data) {

	/* wait for enough space to become available before proceeding */
	while(circ_buf_remainder(buffer) <= 1);

	/* insert data into circular buffer */
	buffer->buffer[buffer->head_ptr++] = data;

	/* loop the pointers in the buffer if required */
	if(buffer->head_ptr == buffer->size_of_buffer) {
		buffer->head_ptr = 0;
	}
	return;
}

/**************************************************************************
 * @brief  unsigned char circ_buf_get_data(circ_buffer_t *buffer)
 *
 * Get a char from the circular buffer
 *
 * @param  none
 *
 * @return none
 **************************************************************************/
unsigned char circ_buf_get_data(circ_buffer_t *buffer) {
    unsigned char ret;

    /* wait for data to become available before proceeding */
    while(circ_buf_remainder(buffer) == buffer->size_of_buffer);

    /* get data from circular buffer */
	ret = buffer->buffer[buffer->tail_ptr++];

	/* loop the pointers in the buffer if required */
	if(buffer->tail_ptr == buffer->size_of_buffer) {
		buffer->tail_ptr = 0;
	}
	return ret;
}
