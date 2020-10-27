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