/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/bitcoin/network/timeout.hpp>

#include <cstdint>
#include <boost/date_time.hpp>

namespace libbitcoin {
namespace network {

using boost::posix_time::seconds;
using boost::posix_time::minutes;

const timeout timeout::defaults(90, 30, 15, 1, 1, 5);

timeout::timeout()
  : timeout(0, 0, 0, 0, 0, 0)
{
}

timeout::timeout(
    uint32_t channel_expiration_minutes,
    uint32_t channel_timeout_minutes,
    uint32_t channel_heartbeat_minutes,
    uint32_t channel_startup_minutes,
    uint32_t channel_revivial_minutes,
    uint32_t connect_timeout_seconds)
  : expiration(0, channel_expiration_minutes, 0),
    inactivity(0, channel_timeout_minutes, 0),
    heartbeat(0, channel_heartbeat_minutes, 0),
    startup(0, channel_startup_minutes, 0),
    revival(0, channel_revivial_minutes, 0),
    connection(0, 0, connect_timeout_seconds)
{
}

} // namespace network
} // namespace libbitcoin
