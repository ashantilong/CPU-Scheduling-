# **CPU-Scheduling - Ashanti Long & Cormac Conahan**

## **1. How Big is a Cache Block?**
### Thought Process:
The first thing we wanted to accomplish is understand what exactly a cache block is. From our research we determined that a cache block is a basic unit for cache storage that typically contains multiple bytes/words of data. This is due to many different regions of memory being mapped into a block; the tag is used to differentiate between them. Upon further research, it was discovered that a typical machine has a cache block of 32 bytes. Knowing this information, we came up with two approaches to implement.

#### Approach 1:
Fill a plain array with random values, and do something simple, e.g. square each element in a loop. Then measure the execution time as a function of the array length. You'll very clearly see a jump in the execution time once your array does not fit into the cache block.
#### Approach 2:

Preallocate a large array. Then access each element sequentially and record the time for each access. Ideally there will be a jump in access time when a cache miss occurs. Then you can calculate your L1 Cache.

#### Actual Approach:

For our approach we are taking an array of integers and we are looping through it and accessing indexes using step variables which are the number of elements we skip and then it increases by (* 2). So for each iteration we theorized that we go to each iteration  using the step. Eventually the cache block size should cause a spike in the index access time because eventually we would need to call another cache block. The below graph contains our experimental values for different step sizes.

### Output and Graph 
![Image of our cache block out](cache_block_access_times.png)

![Image of our cache block graph](cache_block_graph.PNG)


### Interpretation 
We saw the spike start at 32 bytes and it peak at 64 bytes so we decided to experiment with block sizes of 32 bytes and 64 bytes 

## **2. How Big is the Cache?**

### Thought Process:

During our research we discovered that a typical modern  processors typically have a clock cycle of 0.5ns while accesses to main memory are 50ns or more. Thus, an access to main memory is very expensive, over 100 clock cycles. To get good processor performance the average times to fetch instructions and to access data from memory must be reduced.Basically, as the list grows you'll see the performance worsen in steps as another layer of caching is overwhelmed. The idea is simple... if the cache holds the last N units of memory you've accessed, then looping around a buffer of even N+1 units should ensure constant cache misses. (There're more details/caveats in the "measuring latencies of memory" answer you link to in your question). We should be able to get some idea of the potential size of the the largest cache that might front your RAM from hardware documentation - as long as you operate on more memory than that you should be measuring physical RAM times.


### Output and Graph
![Image of our cache size output](cache_size_times.png)

![Image of our cache size graph](cache_size_graph.PNG)


## **3. How Long Does a Reference to Main Memory Take?**

Unfortunately, we used a modulo in the timing block when creating our cache size experiment, which polluted our time a bit. However, judging from the ratio between the spiked and non-spiked accesses, we can assume accesses from main memory to take around 3 times as long as cache references. If, from the question below, we assume cache references to take 2.8 nanoseconds this puts main memory references to around 8.4 nanoseconds.

## **4. How Long Does a Reference that can be Satisfied from Cache Take?**

It would appear, judging from the accesses which didn't cause a "spike" in our cache block experiment, that a reference from cache takes approximately 2.8 nanoseconds.
