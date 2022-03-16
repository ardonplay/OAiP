#include <iostream>
using namespace std;

struct Stack
{
  int info;
  Stack* next;
};


Stack* Push(Stack* stack, int v)
{
  struct Stack* top = new Stack;

  top->info = v;
  top->next = stack;

  return top;
}

Stack* Pop(struct Stack* stack)
{
  if (stack == nullptr)
  {
    return 0;
  }


  int result = stack->info;

  return stack->next;
}

Stack* Input_Stack(int n)
{
  Stack* stack = new Stack;

  for (int i = 0; i < n; i++)
  {
    Stack* current = new Stack;

    cin >> current->info;

    current->next = stack;
    stack = current;
  }
}

void View(Stack* stack)
{
  while (stack != nullptr)
  {
    cout << stack->info << " ";

    stack = stack->next;
  }
}

void Delete_Stack(Stack** stack)
{
    if(*stack != nullptr)
    {
        Stack* curr = *stack;
        Stack* next = (*stack)->next;

        while (next != nullptr)
        {
            delete curr;

            curr = next;
            next = curr->next;
        }
    }

    *stack = nullptr;
}

Stack* Find_Min(Stack* stack)
{
  Stack* min = stack;

  while (stack != nullptr)
  {
    if (stack->info < min->info)
    {
      min = stack;
    }

    stack = stack->next;
  }

  return min;
}
void Sort_p(Stack **p) {
    Stack *t = NULL, *t1, *r;
    if ((*p) -> next -> next == NULL) return;
    do {
        for (t1=*p; t1-> next->next != t; t1=t1-> next)
            if (t1->next->info > t1-> next-> next-> info){ r = t1->next->next;
                t1 -> next -> next = r -> next; r-> next =t1-> next;
                t1-> next = r;
            }
        t= t1-> next;
    } while ((*p)-> next -> next != t);
}

void Sort_info(Stack *p) {
    Stack *t = NULL, *t1;
    int r; do {
        t = t1;
    for (t1=p; t1 -> next != t; t1 = t1-> next)
        if (t1-> info > t1-> next -> info) {
            r = t1->info;
            t1->info = t1->next->info;
            t1->next->info = r;
        }
        } while (p -> next != t);
}

////твоя таска
//Stack* Task1(Stack* top, Stack* min)
//{
//  Stack* stack = nullptr;
//
//  while (top != min)
//  {
//    stack = Push(stack, top->info);
//
//    top = top->next;
//  }
//
//  return stack;
//}
//
//Stack* Task2(Stack* min)
//{
//  Stack* stack = nullptr;
//
//  min = min->next;
//
//  while (min != nullptr)
//  {
//    stack = Push(stack, min->info);
//
//    min = min->next;
//  }
//
//  return stack;
//}

void menu() {
  cout<<"\tMenu\t\n"
          "1.Create stack\n"
          "2.View stack\n"
          "3.Add element\n"
          "4.Delete stack\n"
          "5.Individual task\n"
          "6.Exit"<<endl;
    cout<<">>>";
}

int main()
{
    Stack stack;
    int input = 0, element_of_stack = 0;
    while(true){
        menu();
        cin >> input;
        switch (input) {
            case 1:{
                cout<<"How much elements do you wanna add to your first stack?\n>>>";
                cin >> input;
                for(int j = 0; j < input; j++){
                    cout << "Input " << j << " element of stack: ";
                    cin>>element_of_stack;
                    Push(&stack,element_of_stack);
                    break;
                }
            }
            case 2:{
                View(&stack);
            }
            case 6:{
               return 0;
            }


        }

    }
    menu();

}