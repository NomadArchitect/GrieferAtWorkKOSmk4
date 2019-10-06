/* Copyright (c) 2019 Griefer@Work                                            *
 *                                                                            *
 * This software is provided 'as-is', without any express or implied          *
 * warranty. In no event will the authors be held liable for any damages      *
 * arising from the use of this software.                                     *
 *                                                                            *
 * Permission is granted to anyone to use this software for any purpose,      *
 * including commercial applications, and to alter it and redistribute it     *
 * freely, subject to the following restrictions:                             *
 *                                                                            *
 * 1. The origin of this software must not be misrepresented; you must not    *
 *    claim that you wrote the original software. If you use this software    *
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef _KOS_IO_USB_H
#define _KOS_IO_USB_H 1

#include <__stdinc.h>

#include <bits/types.h>
#include <sys/io.h>

__SYSDECL_BEGIN


#define USB_REQUEST_RETYPE_DESTM 0x1f /* Mask for selecting the destination (recipient) */
#define    USB_REQUEST_RETYPE_DEST_DEV  0x00 /* Device destination */
#define    USB_REQUEST_RETYPE_DEST_INTF 0x01 /* Interface destination */
#define    USB_REQUEST_RETYPE_DEST_ENDP 0x02 /* Endpoint destination */
#define    USB_REQUEST_RETYPE_DEST_OTH  0x03 /* Other (???) */
/*         USB_REQUEST_RETYPE_DEST_...  0x1f  * Other values are reserved */
#define USB_REQUEST_RETYPE_TYPEM 0x60 /* Mask for the type of request to perform (command-namespace). */
#define    USB_REQUEST_RETYPE_TYPE_STD  0x00 /* Standard request */
#define    USB_REQUEST_RETYPE_TYPE_CLS  0x20 /* Device-class-specific request */
#define    USB_REQUEST_RETYPE_TYPE_VEN  0x40 /* Vendor-specific request */
/*         USB_REQUEST_RETYPE_TYPE_     0x60  * Reserved */
#define USB_REQUEST_RETYPE_DIRM  0x80 /* Mask for the transfer direction. */
#define    USB_REQUEST_RETYPE_DIR_H2D   0x00 /* Host-to-device (write/out). */
#define    USB_REQUEST_RETYPE_DIR_D2H   0x80 /* Device-to-host (read/in). */

/* Format of `ur_index' for `USB_REQUEST_RETYPE_DEST_INTF' */
#define USB_REQUEST_INTF_INDEX_ID   0x00ff /* Interface number. */

/* Format of `ur_index' for `USB_REQUEST_RETYPE_DEST_ENDP' */
#define USB_REQUEST_ENDP_INDEX_ID   0x000f /* Endpoint number */
#define USB_REQUEST_ENDP_INDEX_DIRM 0x0080 /* Mask for the transfer direction (how is this
                                            * different from `USB_REQUEST_RETYPE_DIRM'?). */
#define    USB_REQUEST_ENDP_INDEX_DIR_OUT 0x0000 /* Out direction? */
#define    USB_REQUEST_ENDP_INDEX_DIR_IN  0x0080 /* In direction? */



/* Standard (USB_REQUEST_RETYPE_TYPE_STD) USB requests */
#define USB_REQUEST_GET_STATUS 0x00 /* LEN=2 */



#ifdef __CC__
struct __ATTR_PACKED usb_request {
	/* Format of the initial CONTROL packet send to a USB device. */
	__uint8_t  ur_reqtype; /* Request type (Set of `USB_REQUEST_RETYPE_*'). */
	__uint8_t  ur_request; /* The ID of the request (extended by `USB_REQUEST_RETYPE_TYPEM') (One of `USB_REQUEST_*'). */
	__uint16_t ur_value;   /* Potentially optional, request-specific argument (value). */
	__uint16_t ur_index;   /* Potentially optional, request-specific argument (index).
	                        * USB_REQUEST_RETYPE_DEST_INTF: Set of `USB_REQUEST_INTF_INDEX_*'
	                        * USB_REQUEST_RETYPE_DEST_ENDP: Set of `USB_REQUEST_ENDP_INDEX_*' */
	__uint16_t ur_length;  /* USB_REQUEST_RETYPE_DIR_H2D: Exact buffer size of the payload.
	                        * USB_REQUEST_RETYPE_DIR_D2H: Max buffer size of the payload. */
};
#endif /* __CC__ */

__SYSDECL_END

#endif /* !_KOS_IO_USB_H */
