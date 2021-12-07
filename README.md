# **CPU-Scheduling - Ashanti Long & Cormac Conahan**
Our throught process 
our code 
output graph 

interpreation 
## **1. How Big is a Cache Block?**
### Throught Process:
The first thing we wanted to do is understand what a cache block is. From our research we detirmined that a cache block is described as a basic unit for cache storage. It typically contain multiple bytes/words of data. This is due to many different regions of memory being mapped into a block, the tag is used to differentiate between them. A typical machine has a cache block of 32bytes. Knowing this information we came up with two approach  to implement.

#### Approach 1:
Fill a plain array with random values, and do something simple, e.g. square each element in a loop. Then measure the execution time as a function of the array length. You'll very clearly see a jump in the exec time once your array does not fit into the cache.
#### Approach 2:

Preallocate a large array. Then access each element sequentially and record the time for each access. Ideally there will be a jump in access time when cache miss occurs. Then you can calculate your L1 Cache. It might not work but worth trying

#### Actual Approach:

For our approach we are taking an array of integers and we are looping through it and acessing indexes using step variables which are the number of elements we skip and then it increases at by (^ 2). So for each interation we  theroized thatas we go to each iteriation  using the step eventually the cache block size should cause a spike in the index acess time because eventually we would need to call another cache block. As you look below at *Figure 1* below you will see a spike from 16KB to 32KB

### Our Code

### Output and Graph 
![Image of our cache block out](cache_block_access_times.png)

![Image of our cache block graph](cache_block_graph.PNG)


### Interpretation 
We saw the spike start at 32 bytes and it peak at 64 bytes so we decided to experiment with block sizes of 32 bytes and 64 bytes 

## **2. How Big is the Cache?**


## **3. How Long Does a Reference to Main Memory Take?**

## **4. How Long Does a Reference that can be Satisfied from Cache Take?**
