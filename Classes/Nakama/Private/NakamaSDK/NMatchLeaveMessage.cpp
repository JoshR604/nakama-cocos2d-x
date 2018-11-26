/**
 * Copyright 2017 The Nakama Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "NMatchLeaveMessage.h"

namespace Nakama {

	NMatchLeaveMessage::NMatchLeaveMessage(std::string matchId)
	{
		// set our default
		envelope.mutable_matches_leave()->add_match_ids()->assign(matchId);
	}

	NMatchLeaveMessage NMatchLeaveMessage::Default(std::string matchId)
	{
		return NMatchLeaveMessage(matchId);
	}
}
