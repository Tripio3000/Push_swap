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

void 	pushBack(t_stack *src, int num)
{
	t_data *tmp = (t_data *)malloc(sizeof(t_data));
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
	}
}

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
	printf("\n");
}

void 	swap(t_stack *a)
{
	t_data *p1;
	t_data *p2;
	t_data *p3;

	p1 = (*a).head;
	p2 = p1->next;
	p3 = p2->next;
	a->head = p2;
	a->head->prev = NULL;
	a->head->next = p1;
	p1->next = p3;
	if (p3)
		p3->prev = p1;
	else
		a->end = p1;
	p1->prev = p2;

//	print_stack(a);
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
	print_stack(a, 'a');
	print_stack(b, 'b');
}

void 	push1(t_data *p1, t_stack *b)
{
	p1->next = NULL;
	p1->prev = b->end;
	if (b->end)
		b->end->next = p1;
	b->end = p1;
	if (b->head == NULL)
		b->head = p1;
	b->size++;
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
		src->size--;
		return;
	}
	p2 = p1->next;
	src->head = p2;
	src->size--;
	p2->prev = NULL;
	push1(p1, dst);
}

void 	init(t_stack *a, t_stack *b)
{
	a->size = 0;
	a->head = a->end = NULL;
	b->size = 0;
	b->head = b->end = NULL;
}

void 	rev_rotate(t_stack *src)
{
	t_data *p1;
	t_data *p2;

//	ft_putstr("\nmas: ");
//	print_stack(src);

	p1 = src->end;
	p2 = src->end->prev;
	p1->next = src->head;
	p1->prev = NULL;
	if (src->head)
		src->head->prev = p1;
	src->head = p1;
	if (src->end == NULL)
		src->end = p1;
	src->end = p2;
	p2->next = NULL;

//	ft_putstr("\nrotmas: ");
//	print_stack(src);
}

void 	rev_rotation(char *arr, t_stack *a, t_stack *b)
{
	if (ft_strcmp(arr, "rra") == 0 && a->head != NULL && a->head->next != NULL)
		rev_rotate(a);
	if (ft_strcmp(arr, "rrb") == 0 && b->head != NULL && b->head->next != NULL)
		rev_rotate(b);
	if (ft_strcmp(arr, "rrr") == 0 && a->head != NULL && a->head->next != NULL
		&& b->head != NULL && b->head->next != NULL)
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	print_stack(a, 'a');
	print_stack(b, 'b');
}

void 	rotate(t_stack *src)
{
	t_data *p1;
	t_data *p2;

//	ft_putstr("\nmas: ");
//	print_stack(src);

	p1 = src->head;
	p2 = src->head->next;
	p1->next = NULL;
	p1->prev = src->end;
	if (src->end)
		src->end->next = p1;
	src->end = p1;
	if (src->head == NULL)
		src->head = p1;
	src->head = p2;
	p2->prev = NULL;

//	ft_putstr("\nrotmas: ");
//	print_stack(src);
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
	print_stack(a, 'a');
	print_stack(b, 'b');
}

void	ascending_order(t_stack *a, int size)
{
	int i;
	t_data *p1;
	t_data *p2;

//	if (a->size != size)
//	{
//		ft_putstr("KO\n");
//		return ;
//	}
	i = 0;
	p1 = a->head;
	p2 = p1->next;
	while (i < size && p2 != NULL)
	{
		if (p1->num < p2->num)
		{
			p1 = p2;
			p2 = p2->next;
			i++;
		}
		else
		{
			ft_putstr("KO\n");
			return ;
		}
	}
	ft_putstr("OK\n");
}

//		ЧТЕНИЕ СТАНДАРТНОГО ВВОДА
void 	std_input(t_stack *a, t_stack *b)
{
	char *arr;

	while(get_next_line(0, &arr) > 0)
	{
		if (ft_strcmp(arr, "sa") == 0 ||
			ft_strcmp(arr, "sb") == 0 ||
			ft_strcmp(arr, "ss") == 0)
			swapper(arr, a, b);
		if (ft_strcmp(arr, "pb") == 0 && a->head != NULL)
		{
			push(a, b);
			print_stack(a, 'a');
			print_stack(b, 'b');
		}
		if (ft_strcmp(arr, "pa") == 0 && b->head != NULL)
		{
			push(b, a);
			print_stack(a, 'a');
			print_stack(b, 'b');
		}
		if (ft_strcmp(arr, "rra") == 0 ||
			ft_strcmp(arr, "rrb") == 0 ||
			ft_strcmp(arr, "rrr") == 0)
			rev_rotation(arr, a, b);
		if (ft_strcmp(arr, "ra") == 0 ||
			ft_strcmp(arr, "rb") == 0 ||
			ft_strcmp(arr, "rr") == 0)
			rotation(arr, a, b);
	}
}

int 	main(int ac, char **av)
{
	char *arr;
	t_stack *a;
	t_stack *b;
	int size;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	init(a, b);
	create_stack(a, ac, av);
	size = a->size;

	print_stack(a, 'a');
	print_stack(b, 'b');

//	push(a, b);
//	push(a, b);
//	push(b, a);

	std_input(a, b);
	ascending_order(a, size);
	return (0);
}