// Copyright(c) Microsoft.All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// This file is made an integral part of tlsio_openssl_compact.c with a #include. It
// is broken out for readability. 


// The tlsio external state values are the states of the tlsio adapter
// as seen by the caller on the basis of calls made and callbacks received.
#define TLSIO_STATE_EXT_VALUES \
    TLSIO_STATE_EXT_CLOSED, \
    TLSIO_STATE_EXT_OPENING, \
    TLSIO_STATE_EXT_OPEN, \
    TLSIO_STATE_EXT_CLOSING, \
    TLSIO_STATE_EXT_ERROR

DEFINE_ENUM(TLSIO_STATE_EXT, TLSIO_STATE_EXT_VALUES);

// tlsio_verify_internal_state compares the supplied expected_state with the internal state
// of the tlsio adapter, and the expected_message_queue_length with the actual
// message queue length, and uses xlogging to log any discrepancies. It returns 0 if there
// are no discrepancies, and non-zero otherwise. This function is not guaranteed to be 
// accurate during tlsio callbacks.
// This function exists only for unit testing builds and must never be
// called in production code.
int tlsio_verify_internal_state(const CONCRETE_IO_HANDLE tlsio,
	TLSIO_STATE_EXT expected_state, uint32_t expected_message_queue_length);
