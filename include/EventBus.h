#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class EventListener;

struct EventData {
	std::string type = "";
	std::string name = "";
	std::string tag = "";
	int intVal = 0;
	float floatVal = 0.0f;
	bool boolVal = false;
};

class EventBus
{
public:
	static EventBus& getInstance()
	{
		static EventBus instance;
		return instance;
	}

	EventBus() = default;
	~EventBus() = default;

	int bindListener(const std::string& event, EventListener* listener);
	void unBindListener(const std::string& event, int id);
	void fire(const std::string& event, EventData eData = {});

private:

	struct Listener {
		int id = 0;
		EventListener* eventListener = nullptr;
	};

	int nextID = 0;
	std::unordered_map<std::string, std::vector<Listener>> subscribers;

};

class EventListener {
public:
	~EventListener() = default;
	virtual void onEvent(EventData eData) = 0;

protected:
	void listen(const std::string& event);
	void stopListening();
private:
	struct Subscrition {
		std::string event;
		int id;
	};

	std::vector<Subscrition> subscriptions;
};