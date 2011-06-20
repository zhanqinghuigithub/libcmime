/* libcmime - A C mime library
 * Copyright (C) 2010 Axel Steiner <ast@treibsand.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../src/cmime_message.h"

int main (int argc, char const *argv[]) {
	CMimeMessage_T *msg = cmime_message_new();
	char test_sender1[] = "Axel Steiner <ast@treibsand.com>";
	char test_sender2[] = "Foo Bar <foo@foo.bar>";
	char *s = NULL;
	
	cmime_message_set_sender(msg,test_sender1);
	s = cmime_message_get_sender(msg);
	assert(strcmp(s,test_sender1)==0);
	free(s);
	
	// check if sender will be overwritten
	cmime_message_set_sender(msg,test_sender2);
	s = cmime_message_get_sender(msg);
	assert(strcmp(s,test_sender2)==0);
	free(s);
	
	cmime_message_free(msg);
	return(0);
}