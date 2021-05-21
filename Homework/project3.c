#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 100 
#define EXPR_SIZE 100 // �Է��ϴ� ������ �ִ� ũ��

typedef int element; // ���� ����(element)�� �ڷ����� int�� ����

typedef struct
{
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s)
{
    s->top = -1;
}

int is_empty(StackType* s)
{
    return(s->top == -1);
}

int is_full(StackType* s)
{
    return(s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
    if (is_full(s))
    {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else
        s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return
        s->data[(s->top)--];
}

element peek(StackType* s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return
        s->data[s->top];
}

int check_matching(const char* in)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for (int i = 0; i < n; i++)
    {
        ch = in[i];
        switch (ch)
        {
        case '(':case '[': case '{':
            push(&s, ch);
            break;
        case ')': case']': case'}':
            if (is_empty(&s)) return 0;
            else {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
                {
                    return 0;
                }
                break;
            }
        }
    }
    if (!is_empty(&s)) return 0;
    return 1;
}

int prec(char op)
{
    switch (op)
    {
    case '(':case ')': return 0;
    case '+':case '-': return 1;
    case '*':case'/': return 2;
    }
    return -1;
}
void infix_to_postfix(char exp[], char postfix[])
{
    int i = 0;
    int pos = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    init_stack(&s);

    for (i = 0; i < len; i++)
    {
        ch = exp[i];
        switch (ch) {
        case '+': case '-': case '*': case '/':
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
            {
                postfix[pos++] = pop(&s);
            }
            push(&s, ch);
            break;
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s);
            while (top_op != '(')
            {
                postfix[pos++] = top_op;
                top_op = pop(&s);
            }
            break;
        default:
            do {
                postfix[pos++] = ch;
                ch = exp[++i];
            } while (ch >= '0' && ch <= '9');
            postfix[pos++] = ' ';
            i--;
            break;
        }
    }
    while (!is_empty(&s))
    {
        postfix[pos++] = pop(&s);
    }
    postfix[pos] = '\0';
}

int eval(char exp[])
{
    int op1, op2, i = 0;
    int value, pos;
    char temp[100];
    int len = strlen(exp);
    char ch;
    StackType s;
    init_stack(&s);
    for (i = 0; i < len; i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
        { // �Է��� �ǿ������̸�, ���ÿ� push
            value = ch - '0';
            for (pos = 0; exp[i] != ' ';)
            {
                temp[pos++] = exp[i++];
            }
            temp[pos] = '\0';
            value = atoi(temp);
            push(&s, value);
        }
        else if (ch == ' ') continue;
        else
        { //�������̸� �ǿ����ڸ� ���ÿ��� ����
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) { //������ �����ϰ� ���ÿ� ����
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    int result;
    char input[EXPR_SIZE];
    char postfix[EXPR_SIZE];
    while (1)
    {
        printf("����� ������ �Է��ϼ���: ");
        fgets(input, EXPR_SIZE - 1, stdin);
        input[strlen(input) - 1] = '\0';
        if (check_matching(input) != 1) // ��ȣ ���� üũ
        {
            printf("������ �߸��Ǿ����ϴ�.\n\n");
            continue;
        }
        infix_to_postfix(input, postfix);// ���� ǥ����� ���� ǥ������� ��ȯ
        printf("���� ǥ��� : %s\n", postfix);
        result = eval(postfix);// ���� ǥ��� ���
        printf("���� ��� => %d\n\n", result);
    }
}