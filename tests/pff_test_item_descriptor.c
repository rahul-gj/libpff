/*
 * Library item_descriptor type test program
 *
 * Copyright (C) 2008-2023, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "pff_test_libcerror.h"
#include "pff_test_libpff.h"
#include "pff_test_macros.h"
#include "pff_test_memory.h"
#include "pff_test_unused.h"

#include "../libpff/libpff_item_descriptor.h"

#if defined( __GNUC__ ) && !defined( LIBPFF_DLL_IMPORT )

/* Tests the libpff_item_descriptor_initialize function
 * Returns 1 if successful or 0 if not
 */
int pff_test_item_descriptor_initialize(
     void )
{
	libcerror_error_t *error                  = NULL;
	libpff_item_descriptor_t *item_descriptor = NULL;
	int result                                = 0;

#if defined( HAVE_PFF_TEST_MEMORY )
	int number_of_malloc_fail_tests           = 1;
	int number_of_memset_fail_tests           = 1;
	int test_number                           = 0;
#endif

	/* Test regular cases
	 */
	result = libpff_item_descriptor_initialize(
	          &item_descriptor,
	          0,
	          0,
	          0,
	          0,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "item_descriptor",
	 item_descriptor );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libpff_item_descriptor_free(
	          &item_descriptor,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	PFF_TEST_ASSERT_IS_NULL(
	 "item_descriptor",
	 item_descriptor );

	PFF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libpff_item_descriptor_initialize(
	          NULL,
	          0,
	          0,
	          0,
	          0,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	item_descriptor = (libpff_item_descriptor_t *) 0x12345678UL;

	result = libpff_item_descriptor_initialize(
	          &item_descriptor,
	          0,
	          0,
	          0,
	          0,
	          &error );

	item_descriptor = NULL;

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_PFF_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libpff_item_descriptor_initialize with malloc failing
		 */
		pff_test_malloc_attempts_before_fail = test_number;

		result = libpff_item_descriptor_initialize(
		          &item_descriptor,
		          0,
		          0,
		          0,
		          0,
		          &error );

		if( pff_test_malloc_attempts_before_fail != -1 )
		{
			pff_test_malloc_attempts_before_fail = -1;

			if( item_descriptor != NULL )
			{
				libpff_item_descriptor_free(
				 &item_descriptor,
				 NULL );
			}
		}
		else
		{
			PFF_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			PFF_TEST_ASSERT_IS_NULL(
			 "item_descriptor",
			 item_descriptor );

			PFF_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libpff_item_descriptor_initialize with memset failing
		 */
		pff_test_memset_attempts_before_fail = test_number;

		result = libpff_item_descriptor_initialize(
		          &item_descriptor,
		          0,
		          0,
		          0,
		          0,
		          &error );

		if( pff_test_memset_attempts_before_fail != -1 )
		{
			pff_test_memset_attempts_before_fail = -1;

			if( item_descriptor != NULL )
			{
				libpff_item_descriptor_free(
				 &item_descriptor,
				 NULL );
			}
		}
		else
		{
			PFF_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			PFF_TEST_ASSERT_IS_NULL(
			 "item_descriptor",
			 item_descriptor );

			PFF_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_PFF_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( item_descriptor != NULL )
	{
		libpff_item_descriptor_free(
		 &item_descriptor,
		 NULL );
	}
	return( 0 );
}

/* Tests the libpff_item_descriptor_free function
 * Returns 1 if successful or 0 if not
 */
int pff_test_item_descriptor_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libpff_item_descriptor_free(
	          NULL,
	          &error );

	PFF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	PFF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBPFF_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc PFF_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] PFF_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc PFF_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] PFF_TEST_ATTRIBUTE_UNUSED )
#endif
{
	PFF_TEST_UNREFERENCED_PARAMETER( argc )
	PFF_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBPFF_DLL_IMPORT )

	PFF_TEST_RUN(
	 "libpff_item_descriptor_initialize",
	 pff_test_item_descriptor_initialize );

	PFF_TEST_RUN(
	 "libpff_item_descriptor_free",
	 pff_test_item_descriptor_free );

	/* TODO: add tests for libpff_item_descriptor_clone */

	/* TODO: add tests for libpff_item_descriptor_compare */

	/* TODO: add tests for libpff_item_descriptor_get_descriptor_identifier */

#endif /* defined( __GNUC__ ) && !defined( LIBPFF_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

