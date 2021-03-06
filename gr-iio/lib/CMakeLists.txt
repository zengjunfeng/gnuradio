# Copyright 2011,2012 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup the include and linker paths
########################################################################
include_directories(
	${GR_IIO_INCLUDE_DIRS}
    ${GNURADIO_RUNTIME_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
	${IIO_INCLUDE_DIRS}
)

link_directories(
	${Boost_LIBRARY_DIRS}
	${IIO_LIBRARY_DIRS}
)

if(ENABLE_GR_CTRLPORT)
  ADD_DEFINITIONS(-DGR_CTRLPORT)
  include_directories(${ICE_INCLUDE_DIR})
endif(ENABLE_GR_CTRLPORT)

########################################################################
# Setup library
########################################################################
list(APPEND iio_sources
    device_source_impl.cc
    device_sink_impl.cc
	fmcomms2_source_impl.cc
	fmcomms2_sink_impl.cc
)

list(APPEND iio_libs
    gnuradio-runtime
    ${Boost_LIBRARIES}
	${IIO_LIBRARIES}
)

add_library(gnuradio-iio SHARED ${iio_sources})
target_link_libraries(gnuradio-iio ${iio_libs})
GR_LIBRARY_FOO(gnuradio-iio RUNTIME_COMPONENT "iio_runtime" DEVEL_COMPONENT "iio_devel")
