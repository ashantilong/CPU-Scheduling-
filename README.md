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

When doing research we realized that compared to the main memory (RAM), the Processor Cache provides faster access to information, resulting in faster processing of programs and data on a computer. Compared to RAM, Processor Cache Memory is more expensive, which explains the reason for lesser amounts of Processor Cache Memory being used in computers.

Before we started any type of implentation we first check our computer cache size so we could use as a rough estimate to where we should see the spikes.

L1 cache: This is the primary cache embedded in the processor chip. This type of Cache is fast, but it offers very limited storage capacity.
L2 cache: This secondary cache can either be embedded on the processor chip or made available on its own separate chip with a high-speed bus connecting it to the CPU.
L3 cache: This type of processor cache is designed to serve as a backup for L1 and L2 caches. While L3 Cache is slower compared to L1 and L2 Caches, it is faster than RAM and offers significant boost to the performance of L1, L2 Cache.

#### Approach 1:
One approach we could of implenmented was to allocate a BIG char array (make sure it is too big to fit in L1 or L2 cache). Fill it with random data. Start walking over the array in steps of n bytes. Do something with the retrieved bytes, like summing them. Benchmark and calculate how many bytes/second you can process with different values of n, starting from 1 and counting up to 1000 or so. Make sure that your benchmark prints out the calculated sum, so the compiler can't possibly optimize the benchmarked code away. When n == your cache line size, each access will require reading a new line into the L1 cache. So the benchmark results should get slower quite sharply at that point. If the array is big enough, by the time you reach the end, the data at the beginning of the array will already be out of cache again, which is what you want. So after you increment n and start again, the results will not be affected by having needed data already in the cache. So basically we can  measure the cache characteristics, we run our experiment several times, varying the stride and the array size. We make sure that the stride varies at least between 4 bytes and twice the maximal expected cache line size, and that the array size varies from half the minimal expected cache size to at least ten times the maximal expected cache size.

#### Actual Approach:



### Output and Graph
![Image of our cache size output](cache_size_times.png)

![Image of our cache size graph](cache_size_graph.PNG)


## **3. How Long Does a Reference to Main Memory Take?**

Unfortunately, we used a modulo in the timing block when creating our cache size experiment, which polluted our time a bit. However, judging from the ratio between the spiked and non-spiked accesses, we can assume accesses from main memory to take around 3 times as long as cache references. If, from the question below, we assume cache references to take 2.8 nanoseconds this puts main memory references to around 8.4 nanoseconds.

## **4. How Long Does a Reference that can be Satisfied from Cache Take?**

It would appear, judging from the accesses which didn't cause a "spike" in our cache block experiment, that a reference from cache takes approximately 2.8 nanoseconds.
