#include "EventBus.h"

int EventBus::bindListener(const std::string& event, EventListener* listener)
{
	int nID = ++nextID;
	subscribers[event].push_back({ nID, listener });
	return nID;
}

void EventBus::unBindListener(const std::string& event, int id)
{
	auto it = subscribers.find(event);
	if (it == subscribers.end()) {
		return;
	}
	auto& list = it->second;
	for (size_t i = 0; i < list.size(); ++i) {
		if (list[i].id == id) {
			list[i] = list.back();
			list.pop_back();

			if (list.empty()) {
				subscribers.erase(it);
			}
		}
	}
}

void EventBus::fire(const std::string& event, EventData eData)
{
	auto it = subscribers.find(event);
	if (it == subscribers.end())
		return;

	eData.type = event;
	auto& list = it->second;

	for (const auto& entry : list) {
		if (entry.eventListener) {
			entry.eventListener->onEvent(eData);
		}
	}
}

void EventListener::listen(const std::string& event) {
	int id = EventBus::getInstance().bindListener(event, this);
	subscriptions.push_back({ event, id });
}

void EventListener::stopListening()
{
	for (const auto& sub : subscriptions) {
		EventBus::getInstance().unBindListener(sub.event, sub.id);
	}
	subscriptions.clear();
}