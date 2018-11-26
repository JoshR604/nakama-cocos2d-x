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

#pragma once

#include "INCollatedMessage.h"

#include "Defines.h"
#include "NCursor.h"

using namespace server;

namespace Nakama {

	// OnSuccess returns: NResultSet<NLeaderboardRecord>*
	class NAKAMA_API NLeaderboardRecordsFetchMessage : public INCollatedMessage
	{
	private:
		Envelope envelope;
		NLeaderboardRecordsFetchMessage();

	public:
		~NLeaderboardRecordsFetchMessage() {}

		virtual Envelope* GetPayload() override { return &envelope; }
		virtual void SetCollationId(std::string id) override { envelope.set_collation_id(id); }

		class Builder;
	};

	class NAKAMA_API NLeaderboardRecordsFetchMessage::Builder
	{
	private:
		NLeaderboardRecordsFetchMessage message;

	public:
		Builder(std::string leaderboardId);

		Builder Fetch(std::string leaderboardId);
		Builder Limit(int64_t limit);
		Builder Cursor(NCursor cursor);

		NLeaderboardRecordsFetchMessage Build();
	};
}
