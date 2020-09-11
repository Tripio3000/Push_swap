#include "../push_swap.h"

//void 	print_stack(t_stack *list, char a)
//{
//	t_data *p;
//
//	p = list->head;
//	ft_putchar(a);
//	ft_putstr(": ");
//	while (p != NULL)
//	{
//		ft_putnbr(p->num);
//		ft_putchar(' ');
//		p = p->next;
//	}
//	write (1, "\n", 1);
////	printf("\n");
//}

void 	print_stack(t_stack *a, t_stack *b)
{
	t_data *p1;
	t_data *p2;

	ft_printf("+------A------+------B------+\n");
	p1 = a->head;
	p2 = b->head;
	while (p1 != NULL || p2 != NULL)
	{
		if (p1 != NULL)
		{
			ft_printf("|%13d", p1->num);
			p1 = p1->next;
		}
		else
			ft_printf("|             ");
		if (p2 != NULL)
		{
			ft_printf("|%-13d|\n", p2->num);
			p2 = p2->next;
		}
		else
			ft_printf("|             |\n");
	}
	ft_printf("+-------------+-------------+\n");
}

char 	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **mas;

	mas = (char **)malloc(sizeof(char *) * 1000);
	k = 0;
	i = 0;
	while (str[i] < 32)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			j = 0;
			mas[k] = (char *)malloc(sizeof(char) * 1000);
			while (str[i] > 32)
			{
				mas[k][j] = str[i];
				j++;
				i++;
			}
			mas[k][j] = '\0';
			k++;
		}
		else
			i++;
	}
	mas[k] = 0;
	return (mas);
}

void 	ft_init(t_stack *a, t_stack *b)
{
	a->size = 0;
	a->head = a->end = NULL;
	b->size = 0;
	b->head = b->end = NULL;
	a->command = 0;
	a->v = 0;
	b->v = 0;
}

void 	pushBack(t_stack *src, int num)
{
	t_data *tmp;

	tmp = (t_data *)malloc(sizeof(t_data));
	tmp->num = num;
	tmp->next = NULL;
	tmp->prev = src->end;
	if (src->end)
		src->end->next = tmp;
	src->end = tmp;
	if (src->head == NULL)
		src->head = tmp;
	src->size++;
}

void 	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void 	check_valid(char **mas)
{
	int i;
	int j;

	i = 0;
	while (mas[i] != 0)
	{
		if (ft_strlen(mas[i]) > 11)
			error();
		j = 0;
		while (mas[i][j] != '\0')
		{
			if ((mas[i][j] < '0' || mas[i][j] > '9') && mas[i][j] != '-' && mas[i][j] != '+')
				error();
			j++;
		}
		i++;
	}
}

void 	check_duplic(t_stack *a)
{
	t_data *p1;
	t_data *p2;
	int i;

	p1 = a->head;
	while (p1 != NULL)
	{
		i = p1->num;
		p2 = p1->next;
		while (p2 != NULL)
		{
			if (i == p2->num)
				error();
			p2 = p2->next;
		}
		p1 = p1->next;
	}

}

//		ЗАПОЛНЕНИЕ СПИСКА ЧИСЛАМИ ИЗ АРГУМЕНТА
void	create_stack(t_stack *a, int ac, char **av)
{
	int i;
	int j;
	long long num;
	char **mas;

	i = 1;
	if (a->v == 1)
		i = 2;
	while (i < ac)
	{
		mas = ft_split(av[i]);
		check_valid(mas);
		j = 0;
		while (mas[j] != 0)
		{
			num = ft_atoi_long(mas[j]);
			if (num > 2147483647 || num < -2147483648)
				error();
			pushBack(a, num);
			j++;
		}
		i++;
		j = 0;
		while (mas[j] != 0)
		{
			ft_memdel((void *)(&mas[j]));
			j++;
		}
		ft_memdel((void *)&mas);
	}
	check_duplic(a);
}

void 	ft_freee(t_stack *a, t_stack *b)
{
	t_data *p;
	t_data  *tmp;

	p = a->head;
	while (p != NULL)
	{
		tmp = p->next;
		ft_memdel((void *)&p);
		p = tmp;
	}
	ft_memdel((void *)&a);
	ft_memdel((void *)&b);
}