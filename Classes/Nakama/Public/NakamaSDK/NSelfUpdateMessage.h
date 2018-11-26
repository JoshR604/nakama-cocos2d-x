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

using namespace server;

namespace Nakama {

	// OnSuccess returns: nothing (nullptr)
	class NAKAMA_API NSelfUpdateMessage : public INCollatedMessage
	{

	private:
		Envelope envelope;
		NSelfUpdateMessage();

	public:
		~NSelfUpdateMessage() {}

		virtual Envelope* GetPayload() override { return &envelope; }
		virtual void SetCollationId(std::string id) override { envelope.set_collation_id(id); }

		class Builder;
	};

	class NAKAMA_API NSelfUpdateMessage::Builder
	{
	private:
		NSelfUpdateMessage message;

	public:
		Builder() {}

		Builder AvatarUrl(std::string avatarUrl);
		Builder Handle(std::string handle);
		Builder Fullname(std::string fullname);
		Builder Lang(std::string lang);
		Builder Location(std::string location);
		Builder Metadata(std::string metadata);
		Builder Timezone(std::string timezone);

		NSelfUpdateMessage Build();
	};
}
