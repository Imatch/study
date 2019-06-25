c++知识

1.mutable的中文意思是“可变的，易变的”
在C++中，mutable也是为了突破const的限制而设置的。被mutable修饰的变量，将永远处于可变的状态，即使在一个const函数中
如果类的成员函数不会改变对象的状态，那么这个成员函数一般会声明成const的。但是，有些时候，我们需要在const的函数里面修改一些跟类状态无关的数据成员，那么这个数据成员就应该被mutalbe来修饰。
class  class BlockingQueue
{ 
	size_t size() const			//const修饰函数不能改变状态
	{
		MutexLockGuard lock(mutex_);		//上锁，改变锁状态，所以mutex_声明为mutable
		return queue_.size();
	}

private:
  mutable MutexLock mutex_;
  std::deque<T>     queue_ GUARDED_BY(mutex_);
}

