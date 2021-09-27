/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:36:29 by ayajrhou          #+#    #+#             */
/*   Updated: 2021/07/06 10:36:31 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct t_node
{
	int				value;
	struct t_node	*next;
}				t_node;

void	ft_swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

t_node	*bubblesort(t_node *stack, int n)
{
    int	i;
    int	j;
    int	*tab;
    t_node	*tmp;
    t_node *ret;

    ret = stack;
    i = 0;
    tmp = stack;
    tab = malloc(sizeof(int) * n);
    while(stack)
    {
        tab[i] = stack->value;
        stack = stack->next;
        i++;
    }
    i = 0;
    while(i < n - 1)
    {
        j = 0;
        while(j < n-i-1)
        {
            if(tab[j] > tab[j + 1])
                ft_swap(&tab[j],&tab[j+1]);
            j++;
        }
        i++;
    }
	i = 0;
	while (tmp)
	{
		i = -1;
		while (++i < n)
		{
			if (tmp->value == tab[i])
			{
				tmp->value = i;
				//printf("DBG : [%d]\n", tmp->value);
				tmp = tmp->next;
				break;
			}
		}
	}
	free(tab);
	return ret;
}
  
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}
t_node	*swap_a(t_node *stack)
{
	ft_putstr("sa\n");
	t_node *tmp;
	int		value;

	value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value;
	return(stack);
}
t_node	*swap_b(t_node *stack)
{
	ft_putstr("sb\n");
	t_node *tmp;
	int		value;

	value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = value;
	return(stack);
}

t_node	*rotate_reverse_a(t_node *stack, int indicate)
{
	ft_putstr("rra\n");
	t_node *foot;
	t_node *head;
	t_node *beforand;

	head = stack;
	beforand = stack;
	while(stack->next)
	{
		stack = stack->next;
	}
	while(beforand->next->next)
	{
		beforand = beforand->next;
	}
	foot = stack;
	foot->next = head;
	beforand->next = NULL;
	return foot;
	
	
}
int	a_is_sorted(t_node *stack, int flag)
{
	while(stack->next && stack->value < stack->next->value)
	{
		stack = stack->next;
		if(stack->next == NULL && flag == 1)
		{
			if(!(flag == 0))
				exit(0);
		return(1); //ft_exit("the list is sorted");
		}
	}
return(0);
}
t_node	*rotate_a(t_node *stack)
{
	ft_putstr("ra\n");
	t_node *tmp;
	t_node *head;

	head = stack->next;
	tmp = stack;
	while(stack->next)
		stack = stack->next;
	stack->next = tmp;
	tmp->next = NULL;
	return head;
}

t_node	*rotate_b(t_node *stack)
{
	ft_putstr("rb\n");
	t_node *tmp;
	t_node *head;

	head = stack->next;
	tmp = stack;
	while(stack->next)
		stack = stack->next;
	stack->next = tmp;
	tmp->next = NULL;
	return head;
}
t_node	*rotate_reverse_b(t_node *stack, int indicate)
{
	ft_putstr("rrb\n");
	t_node *tmp;
	t_node *befinal;

	int		i;

	i = 0;
	tmp = stack;
	while(stack->next)
	{
		stack = stack->next;
		i++;
		if (i == indicate - 2)
		{
			befinal = stack;
			befinal->next = NULL;
		}
		
	}
	stack = tmp;
	return stack;
}

void	push_b(t_node **stack_b , t_node **stack_a)
{
	ft_putstr("pb\n");
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = (*stack_a)->next;
	tmp_b = (*stack_a);
	tmp_b->next = *(stack_b);
	(*stack_b) = tmp_b;
	(*stack_a) = tmp_a;
}

void	push_a(t_node **stack_b , t_node **stack_a)
{
	ft_putstr("pa\n");
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_b = (*stack_b)->next;
	tmp_a = (*stack_b);
	tmp_a->next = *(stack_a);
	(*stack_a) = tmp_a;
	(*stack_b) = tmp_b;
}
int	bits_calculator(int size)
{
	int		max_value;
	int		c;

	c = 0;
	max_value = size - 1;
	while (max_value)
	{
		c++;
		max_value >>= 1;
	}
	return (c);
}
void	ft_sort_binary(t_node **stack_a, t_node **stack_b, int i, int size)
{
	int j;

	j = size;
	while(j--)
	{
		if (!((*stack_a)->value >> i & 1))
		{
			push_b(stack_b,stack_a);
			//ft_putstr("pb\n");
		}
		else
		{
			(*stack_a) = rotate_a(*stack_a);
		}
	}
}
void	ft_bit_sort(t_node **stack_a, t_node **stack_b,int size)
{
	int bits;
	int i;

	i = 0;
	bits = bits_calculator(size);
	while(i < bits)
	{
		ft_sort_binary(stack_a,stack_b,i, size);
		while ((*stack_b))
		{
			push_a(stack_b, stack_a);
		}
		i++;
	}

}

t_node  *fillstack(char **array, int size)
{
    t_node *stack;
    t_node *tmp;
    int i;

    i = 1;
    if (size < 0)
        return (NULL);
    stack = (t_node *)malloc(sizeof(t_node) * 1);
    tmp = stack;
    if (!stack)
        return (NULL);
    stack->value = atoi(array[i++]);
    stack->next = NULL;
    while (i <= size)
    {
        stack->next = (t_node *)malloc(sizeof(t_node) * 1);
        stack->next->value = atoi(array[i++]);
        stack->next->next = NULL;
        stack = stack->next;
    }
    return (tmp);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	ft_duplicate_error(char **argv,int i)
{
	int j;

	j = 1;
	while(j < i)
	{
		if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
			ft_exit("Error");
		j++;
	}
}
void	ft_error_tratement(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(argv[i])
	{
		while(argv[i][j])
		{
			if(argv[i][j] == '-')
					j++;
			if (!ft_isdigit(argv[i][j]))
				ft_exit("Error");
			j++;
		}
		ft_duplicate_error(argv,i);
		j = 0;
		i++;
	}
	
}

t_node	*ft_3_num(t_node *stack_a)
{
	int		fr;
	int		sec;
	int		th;
	t_node	*start;

	start = stack_a;
	fr = start->value;
	sec = start->next->value;
	th = start->next->next->value;
	if (fr > sec && fr < th && sec < th)
		stack_a = swap_a(stack_a);
	else if (fr > sec && fr > th && sec > th)
	{
		stack_a = swap_a(stack_a);
		stack_a = rotate_reverse_a(stack_a,5);
	}
	else if (fr > sec && fr > th && sec < th)
		stack_a = rotate_a(start);
	else if (fr < sec && fr < th && sec > th)
	{
		stack_a = swap_a(stack_a);
		stack_a = rotate_a(stack_a);
	}
	else if (fr < sec && fr > th && sec > th)
		stack_a = rotate_reverse_a(stack_a,5);
    return stack_a;
}
t_node	*ft_comparing_stack(t_node *stack_a, t_node *stack_b)
{
	t_node *tmp;
	tmp = stack_a;
	if(stack_b->value > stack_b->next->value)
		stack_b = rotate_b(stack_b);
	if(stack_b->value < stack_a->value)
		push_a(&stack_b,&stack_a);
	stack_a = rotate_reverse_a(stack_a,4);
	while(stack_a->next)
	{
		if (stack_b->value == stack_a->value - 1)
		{
			push_a(&stack_b,&stack_a);
		}
		else
			stack_a = rotate_reverse_a(stack_a,4);
		//printf("%ddbg\n",stack_a->next->value);
		stack_a = stack_a->next;
	}

	return tmp;
}

t_node	*ft_5_num(t_node *stack_a,t_node *stack_b)
{
	push_b(&stack_b,&stack_a);
	push_b(&stack_b,&stack_a);
	if(a_is_sorted(stack_a,0))
		stack_a = ft_3_num(stack_a);
	stack_a = ft_comparing_stack(stack_a,stack_b);
	// while(stack_b)
	// {
	// 	printf("b = |%d|\n",stack_b->value);
	// 	stack_b = stack_b->next;
	// }
	// push_a(&stack_b,&stack_a);
	// stack_a = rotate_a(stack_a);
	// push_a(&stack_b,&stack_a);
	return stack_a;
}

void	ft_check_stackb(t_node **stack_a,t_node **stack_b,int c)
{
	if (c == 5)
	{
		if((*stack_b)->value < (*stack_b)->next->value)
		{
			*stack_b = rotate_b(*stack_b);
		}
		push_a(stack_b,stack_a);
		push_a(stack_b,stack_a);
	}
	else
		push_a(stack_b,stack_a);
}
t_node	*ft_4_num(t_node *stack_a,t_node *stack_b,int i)
{
	int c;
	int b;

	b = i;
	c = i;
	
	while(i)
	{
		if(stack_a->value == 0)
		{
			push_b(&stack_b,&stack_a);
			c--;
		}
		if(stack_a->value == 1 && b == 5)
		{
			push_b(&stack_b,&stack_a);
			c--;
		}
		stack_a = rotate_reverse_a(stack_a,c);
		i--;
	}
    
	stack_a = ft_3_num(stack_a);
    
	ft_check_stackb(&stack_a,&stack_b,b);
    
	return stack_a;
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_check_int(char **argv)
{
	int i;
	int j;
	char *str;

	i = 1;
	while(argv[i])
	{
		j = ft_atoi(argv[i]);
		str = ft_itoa(j);
		if (strcmp(str,argv[i]))
			ft_exit("error");
		free(str);
		i++;
	}
}

int main(int argc , char **argv)
{
	t_node *stack_a;
	t_node *stack_b;
	char **tab;
	int len;

	if (argc == 1)
	 	ft_exit("");
	ft_check_int(argv);
	stack_a = fillstack(argv, argc - 1);
	stack_b = NULL;
	len = argc - 1;
	ft_error_tratement(argv);
	bubblesort(stack_a,argc - 1);
	 a_is_sorted(stack_a,1);
	if (argc == 3)
		stack_a = rotate_a(stack_a);
	 else if(argc == 4)
		 stack_a = ft_3_num(stack_a);
	else if (argc == 5)
		stack_a = ft_4_num(stack_a,stack_b,4);
	else if (argc == 6)
		stack_a = ft_4_num(stack_a,stack_b,5);
	else
		ft_bit_sort(&stack_a,&stack_b,argc - 1);
	    system("leaks push_swap");

}

