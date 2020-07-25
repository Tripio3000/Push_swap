#include "../push_swap.h"

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

//		ЗАПОЛНЕНИЕ СПИСКА ЧИСЛАМИ ИЗ АРГУМЕНТА
void	create_stack(t_stack *a, int ac, char **av)
{
	int i;
	int j;
	char **mas;

	i = 1;
	while (i < ac)
	{
		mas = ft_split(av[i]);
		j = 0;
		while (mas[j] != 0)
		{
			t_data *tmp = (t_data *)malloc(sizeof(t_data));
			tmp->num = ft_atoi(mas[j]);
			tmp->next = NULL;
			tmp->prev = a->end;
			if (a->end)
				a->end->next = tmp;
			a->end = tmp;
			if (a->head == NULL)
				a->head = tmp;
			a->size++;
//			printf("current: %d\n", a->end->num);
			j++;
		}
		i++;
	}
}

void 	print_stack(t_stack *list)
{
	t_data *p;

	p = list->head;
	while (p != NULL)
	{
		ft_putnbr(p->num);
		ft_putchar(' ');
		p = p->next;
	}
}

void 	swap(t_stack *a)
{
	t_data *p1;
	t_data *p2;
	t_data *p3;

//	p = (t_stack *)malloc(sizeof(t_stack));
	p1 = (*a).head;
	p2 = p1->next;
	p3 = p2->next;
	a->head = p2;
	a->head->prev = NULL;
	a->head->next = p1;
	p1->next = p3;
	if (p3)
		p3->prev = p1;
	p1->prev = p2;

	print_stack(a);
}

void 	push1(t_data *p1, t_stack *b)
{
	t_data *p2;

	if (b->head == NULL)
	{
		b->head = p1;
		b->head->next = NULL;
	}
	else
	{
		p2 = b->head;
		b->head = p1;
		p1->next = p2;
		p1->prev = NULL;
		p2->prev = p1;
	}
}

void 	push(t_stack *src, t_stack *dst)
{
	t_data *p1;
	t_data *p2;

	p1 = src->head;
	if (p1->next == NULL)
	{
		push1(p1, dst);
		src->head = NULL;
		printf("\na: ");
		print_stack(src);
		printf("\nb: ");
		print_stack(dst);
		return;
	}
	p2 = p1->next;
	src->head = p2;
	p2->prev = NULL;
	push1(p1, dst);

	ft_putstr("\na: ");
	print_stack(src);
	ft_putstr("\nb: ");
	print_stack(dst);
	printf("\n");
}

void 	init(t_stack *a, t_stack *b)
{
	a->size = 0;
	a->head = a->end = NULL;
	b->size = 0;
	b->head = b->end = NULL;
}

void 	swapper(char *arr, t_stack *a, t_stack *b)
{
	if (ft_strcmp(arr, "sa") == 0 && a->head != NULL && a->head->next != NULL)
		swap(a);
	if (ft_strcmp(arr, "sb") == 0 && b->head != NULL && b->head->next != NULL)
		swap(b);
	if (ft_strcmp(arr, "ss") == 0 && a->head != NULL && a->head->next != NULL
	&& b->head != NULL && b->head->next != NULL)
	{
		swap(a);
		swap(b);
	}
}

void 	rotate(t_stack *src)
{
	t_data *p1;
	t_data *p2;

	ft_putstr("\nmas: ");
	print_stack(src);

	p1 = src->head;
	p2 = src->end->prev;
	src->head = src->end;
	src->head->prev = NULL;
	src->head->next = p1;
	p2->next = NULL;

	ft_putstr("\nrotmas: ");
	print_stack(src);
}

void 	rotation(char *arr, t_stack *a, t_stack *b)
{
	if (ft_strcmp(arr, "ra") == 0 && a->head != NULL && a->head->next != NULL)
		rotate(a);
	if (ft_strcmp(arr, "rb") == 0 && b->head != NULL && b->head->next != NULL)
		rotate(b);
	if (ft_strcmp(arr, "rr") == 0 && a->head != NULL && a->head->next != NULL
		&& b->head != NULL && b->head->next != NULL)
	{
		rotate(a);
		rotate(b);
	}

}

int 	main(int ac, char **av)
{
	char *arr;
	t_stack *a;
	t_stack *b;
	int i;
	int k;
	int j;
	int num;
	char **mas;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	init(a, b);
	create_stack(a, ac, av);

	ft_putstr("a: ");
	print_stack(a);
	ft_putstr("\nb: ");
	print_stack(b);
	printf("\n");

	rotate(a);

//	push(a, b);
//	swap(a);

//		ЧТЕНИЕ СТАНДАРТНОГО ВВОДА
//	while(get_next_line(0, &arr) > 0)
//	{
//		if (ft_strcmp(arr, "sa") == 0 ||
//			ft_strcmp(arr, "sb") == 0 ||
//			ft_strcmp(arr, "ss") == 0)
//			swapper(arr, a, b);
//		if (ft_strcmp(arr, "pb") == 0 && a->head != NULL)
//			push(a, b);
//		if (ft_strcmp(arr, "pa") == 0 && b->head != NULL)
//			push(b, a);
//		if (ft_strcmp(arr, "ra") == 0 ||
//			ft_strcmp(arr, "rb") == 0 ||
//			ft_strcmp(arr, "rr") == 0)
//			rotation(arr, a, b);
//
//	}
	printf("\nHello    world\n");
	return (0);
}