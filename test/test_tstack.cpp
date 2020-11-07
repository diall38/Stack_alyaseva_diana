#include "stack.h"

#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> st(3));
}
TEST(Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-3));
}
TEST(Stack, can_get_size)
{
	Stack<int> st(3);
	for (int i = 0; i < 3; i++) {
		st.size++;
		st[i] = i + 1;
	}
	EXPECT_EQ(3, st.Size());
}
TEST(Stack, can_get_top)
{
	Stack<> st(3);
	for (int i = 0; i < 3; i++) {
		st.size++;
		st[i] = i + 1;
	}
	EXPECT_EQ(3, st.top());
}
TEST(Stack, can_check_empty)
{
	Stack<> st(3);
	EXPECT_EQ(true, st.empty());
}
TEST(Stack, can_check_full)
{
	Stack<> st(3);
	for (int i = 0; i < 3; i++){
		st.size++;
		st[i] = i + 1;
}
	EXPECT_EQ(true, st.full());
}

TEST(Stack, can_pop_value)
{
	Stack<> st(3);
	for (int i = 0; i < 3; i++){
		st.size++;
		st[i] = i + 1;
}
	st.pop();
	EXPECT_EQ(2, st.size);
	EXPECT_EQ(2, st[st.size - 1]);
}
TEST(Stack, can_push_value)
{
	Stack<> st(3);
	for (int i = 0; i < 3; i++){
		st.size++;
		st[i] = i + 1;
	}
	st.push(4);
	EXPECT_EQ(4, st.size);
	EXPECT_EQ(4, st[st.size - 1]);
}


TEST(Queue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> q(3));
}
TEST(Queue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<> q(-3));
}
TEST(Queue, can_get_size)
{
	Queue<> q(3);
	for (int i = 0; i < 3; i++) {
		q.size++;
		q[i] = i + 1;
	}
	EXPECT_EQ(3, q.Size());
}
TEST(Queue, can_pop_value)
{
	Queue<> q(5);
	for (int i = 0; i < 5; i++) {
		q.size++;
		q[i] = i;
	}
	q.pop();
	EXPECT_EQ(4, q.size);
	EXPECT_EQ(1, q.front());
	EXPECT_EQ(4, q.back());
}
TEST(Queue, can_push_value_size_less_than_capacity)
{
	Queue<> q(5);
	for (int i = 0; i < 5; i++) {
		q.size++;
		q[i] = i;
	}
	q.pop();
	q.pop(); //front==2 back==4
	q.push(10); 
	EXPECT_EQ(4, q.size);
	EXPECT_EQ(10, q.back());
	EXPECT_EQ(2, q.front());
}
TEST(Queue, can_push_value_size_equal_with_capacity)
{
	Queue<> q(5);
	for (int i = 0; i < 5; i++) {
		q.size++;
		q[i] = i;
	}
	q.pop();
	q.pop(); //front==2 back==4
	q.push(10);//back==0
	q.push(9);//back==1
	q.push(8);//back==6
	//10 9 2 3 4 + 8 -> 2 3 4 10 9 8
	EXPECT_EQ(6, q.size);
	EXPECT_EQ(8, q.back());
	EXPECT_EQ(2, q.front());
}
TEST(QueueTS, can_create_queue_on_two_stacks)
{
	ASSERT_NO_THROW(QueueTS<> q);
}
TEST(QueueTS, can_push_elem)
{
	QueueTS<> q;
	ASSERT_NO_THROW(q.push(1));
	EXPECT_EQ(1, q.Size());
}
TEST(QueueTS, can_get_size)
{
	QueueTS<> q;
	for (int i = 0; i < 3; i++) 
		q.push(i);
	EXPECT_EQ(3, q.Size());
}
TEST(QueueTS, can_pop_elem)
{
	QueueTS<> q;
	for (int i = 0; i < 3; i++)
		q.push(i);
	ASSERT_NO_THROW(q.pop());
	EXPECT_EQ(2, q.Size());
}