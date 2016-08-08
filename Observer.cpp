struct Event
{
	//const String EVENT_ID;
	const string EVENT_NAME;
	const int EVENT_ID;
}Event;



Enum Events{Event1,Event2}



class IListener
{
	
	public:
	       IListener()
	       {

	       }

	       ~IListener(){}

	       void onNotify()=0;
}


class DummyListener:public IListener
{
	
	public:
	      DummyListener()
	      {

	      }

	      ~DummyListener
	      {

	      }

	      void onNotify() override
	      {
	      		//GENERATE SOME EVENTS
	      }	
}




class Object
{
	//vector<IListener*>listeners;
	Event event;
	map<Event,IListener>object_holder;
	public:
	      Object()
	      {

	      }

	      ~Object(){}

	      void registerListener(const Event& event , const IListener*);
	      void unregisterListener(const Event& event , const IListener*);
	      void notifyListener(const Event& event , const IListener*);
	      void notifyAll();
}


void Object::registerListener(const Event& event , const IListener* iListener)
{

	object_holder.insert<Event,IListener*>(event,iListener);
}


void Object::unregisterListener(const Event& event)
{
	for(auto i : listeners)
	{
		if((*i)->first.EVENT_NAME == event.EVENT_NAME && (*i)->first.EVENT_ID == event.EVENT_ID)
		{
			object_holder.erase(*i);
		}
	}
}

//THIS MODULE WILL NOTIFY THE SPECIFIC 
void Object :: notifyListener(const Event& event)
{
	for(auto i : listeners)
	{
		if((*i)->first.EVENT_NAME == event.EVENT_NAME && (*i)->first.EVENT_ID == event.EVENT_ID)
		{
			IListener* listener = (*i)->second;
			listener.onNotify();
		}
	}
}


//THIS MODULE WILL NOTIFY ALL THE LISTENER THAT HAS BEEN REGISTERED IN EventManager
void Object :: notifyAll()
{
	for(auto i : listeners)
	{
		IListener* listener = (*i)->second;
		listener.onNotify();
	}
}





//THIS IS THE WRAPPER CLASS WHICH WILL MANAGER ALL THE LISTERNER REGISTRATION 

class EventManager
{
	
	Object* object;
	static EventManager* eventHandler;
	
		EventManager()
		{
			object = new Object();
		}


		~EventManager()
		{
			delete object;
		}

    public:

    	static EventManager* getInstance()
    	{
    		if(!eventHandler)
    		{
    			eventHandler = new EventManager();

    		}

    		return eventHandler;
    	}


		void SubscribeListener(const Event& event , const IListener* iListener)
		{
			object.registerListener(event , iListener);
		}	

		void UnSubscribeListener(const Event& event)
		{
			object.unregisterListener(event);
		}


		void NotifyListener(const Event& event)
		{
			object.notifyListener(event);
		}

}




class client
{
	
	public:
		client()
		{
			EVENT event;
			event.EVENT_NAME = "CLIENT_EVENT";
			event.EVENT_ID = hash("CLIENT_ID");
			EventManager->SubscribeListener(event,new DummyListener());
		}


		~client()
		{
			EventManager->UnSubscribeListener(event);
		}

		void notification();

}



void client::notification()
{
			
	EventManager->getInstance()->NotifyListener(event);
}
