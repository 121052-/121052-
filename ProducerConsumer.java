public class ProducerConsumer 
{

static Monitor monitor;

public ProducerConsumer(int maxSize)
{
	monitor = new Monitor(maxSize);
	new Producer().start();
	new Producer().start();
	new Consumer().start();
	new Consumer().start();
}

class Producer extends Thread
{

@Override
public void run() 
	{
		while(true)
		{
				try {
					monitor.insert();
				} catch (InterruptedException e) {
				e.printStackTrace();
				}
         }
     }
 }

class Consumer extends Thread
{

@Override
public void run() 
		{
			while(true)
            {
				try {
				monitor.remove();
				} catch (InterruptedException e) {
				e.printStackTrace();
                }
            }
        }
 }

class Monitor 
{

int n;
int maxSize;

public Monitor(int maxSize)
         {
             n=0;
			this.maxSize = maxSize;
         }

synchronized void insert() throws InterruptedException
        {
			if(n==maxSize)
			wait();
			System.out.println("Producer: "+n++);
			if(n==1)
			notifyAll();
        }

synchronized void remove() throws InterruptedException
        {
			if(n==0)
				wait();
			System.out.println("Consumer: "+n--);
			if(n==maxSize-1)
				notifyAll();
        }
}

public static void main(String[] args) 
	{
		ProducerConsumer pc = new ProducerConsumer(10);

    }
}
