/* -*- c++ -*- */
/* 
 * Copyright 2014 Analog Devices Inc.
 * Author: Paul Cercueil <paul.cercueil@analog.com>
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_IIO_DEVICE_SINK_IMPL_H
#define INCLUDED_IIO_DEVICE_SINK_IMPL_H

#include <string>
#include <vector>

#include <iio.h>
#include <gnuradio/iio/device_sink.h>

namespace gr {
  namespace iio {

    class device_sink_impl : public device_sink
    {
     protected:
	     struct iio_context *ctx;
	     struct iio_buffer *buf;
	     std::vector <struct iio_channel *> channel_list;
	     unsigned int buffer_size;

     public:
      device_sink_impl(const std::string &host, const std::string &device,
		      const std::vector<std::string> &channels,
		      unsigned int buffer_size = DEFAULT_BUFFER_SIZE,
		      bool cyclic = false);
      ~device_sink_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);

      void forecast(int noutput_items, gr_vector_int &ninput_items_required);
    };

  } // namespace iio
} // namespace gr

#endif /* INCLUDED_IIO_DEVICE_SINK_IMPL_H */
