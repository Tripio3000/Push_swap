#include "../push_swap.h"

void 	print_stack(t_stack *list, char a)
{
	t_data *p;

	p = list->head;
	ft_putchar(a);
	ft_putstr(": ");
	while (p != NULL)
	{
		ft_putnbr(p->num);
		ft_putchar(' ');
		p = p->next;
	}
	write (1, "\n", 1);
//	printf("\n");
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

void 	init(t_stack *a, t_stack *b)
{
	a->size = 0;
	a->head = a->end = NULL;
	b->size = 0;
	b->head = b->end = NULL;
	a->command = 0;
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

//		ЗАПОЛНЕНИЕ СПИСКА ЧИСЛАМИ ИЗ АРГУМЕНТА
void	create_stack(t_stack *a, int ac, char **av)
{
	int i;
	int j;
	int num;
	char **mas;

	i = 1;
	while (i < ac)
	{
		mas = ft_split(av[i]);
		j = 0;
		while (mas[j] != 0)
		{
			num = ft_atoi(mas[j]);
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
}