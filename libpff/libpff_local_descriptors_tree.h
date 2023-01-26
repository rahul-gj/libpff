/*
 * Local descriptors tree functions
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

#if !defined( _LIBPFF_LOCAL_DESCRIPTORS_TREE_H )
#define _LIBPFF_LOCAL_DESCRIPTORS_TREE_H

#include <common.h>
#include <types.h>

#include "libpff_io_handle.h"
#include "libpff_libbfio.h"
#include "libpff_libcerror.h"
#include "libpff_libfcache.h"
#include "libpff_libfdata.h"
#include "libpff_local_descriptor_value.h"
#include "libpff_offsets_index.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libpff_local_descriptors_tree libpff_local_descriptors_tree_t;

struct libpff_local_descriptors_tree
{
	/* The IO handle
	 */
	libpff_io_handle_t *io_handle;

	/* The offsets index
	 */
	libpff_offsets_index_t *offsets_index;

	/* The descriptor identifier
	 */
	uint32_t descriptor_identifier;

	/* The root data identifier
	 */
	uint64_t root_data_identifier;

	/* Value to indicate if the local descriptors were recovered
	 */
	uint8_t recovered;

	/* Recovered value index
	 */
	int recovered_value_index;

	/* The tree
	 */
	libfdata_tree_t *tree;
};

int libpff_local_descriptors_tree_initialize(
     libpff_local_descriptors_tree_t **local_descriptors_tree,
     libpff_io_handle_t *io_handle,
     libpff_offsets_index_t *offsets_index,
     uint32_t descriptor_identifier,
     uint64_t root_data_identifier,
     uint8_t recovered,
     int recovered_value_index,
     libcerror_error_t **error );

int libpff_local_descriptors_tree_free(
     libpff_local_descriptors_tree_t **local_descriptors_tree,
     libcerror_error_t **error );

int libpff_local_descriptors_tree_clone(
     libpff_local_descriptors_tree_t **destination_local_descriptors_tree,
     libpff_local_descriptors_tree_t *source_local_descriptors_tree,
     libcerror_error_t **error );

int libpff_local_descriptors_tree_get_leaf_node_by_identifier(
     libpff_local_descriptors_tree_t *local_descriptors_tree,
     libbfio_handle_t *file_io_handle,
     libfcache_cache_t *cache,
     uint64_t identifier,
     libfdata_tree_node_t **leaf_local_descriptors_tree_node,
     libcerror_error_t **error );

int libpff_local_descriptors_tree_node_get_leaf_node_by_identifier(
     libfdata_tree_node_t *local_descriptors_tree_node,
     libbfio_handle_t *file_io_handle,
     libfcache_cache_t *cache,
     uint64_t identifier,
     libfdata_tree_node_t **leaf_local_descriptors_tree_node,
     libcerror_error_t **error );

int libpff_local_descriptors_tree_get_value_by_identifier(
     libpff_local_descriptors_tree_t *local_descriptors_tree,
     libbfio_handle_t *file_io_handle,
     libfcache_cache_t *cache,
     uint64_t identifier,
     libpff_local_descriptor_value_t **local_descriptor_value,
     libcerror_error_t **error );

int libpff_local_descriptors_tree_read(
     libpff_local_descriptors_tree_t **local_descriptors_tree,
     libpff_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     libpff_offsets_index_t *offsets_index,
     uint32_t descriptor_identifier,
     uint64_t data_identifier,
     uint8_t recovered,
     int recovered_value_index,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBPFF_LOCAL_DESCRIPTORS_TREE_H ) */

