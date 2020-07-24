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

int 	main(int ac, char **av)
{
	char *arr;
	t_stack *list;
	int i;
	int k;
	int j;
	int num;
	char **mas;

	i = 1;
	k = 0;
	list = (t_stack *)malloc(sizeof(t_stack));
	while (i < ac)
	{
		mas = ft_split(av[i]);
		j = 0;
		while (mas[j] != 0)
		{
			list->data.a = ft_atoi(mas[j]);
			printf("%d\n", list->data.a);
			list->next = (t_stack *)malloc(sizeof(t_stack));
			list = list->next;
			j++;
		}
		i++;
	}


//	list = (t_stack *)malloc(sizeof(t_stack));
//	i = 1;
//	while (i < ac)
//	{
//		list->data.a = av[i][0] - '0';
//		printf("%d\n", list->data.a);
//		list->next = (t_stack *)malloc(sizeof(t_stack));
//		list = list->next;
//		i++;
//	}
//	while(get_next_line(0, &arr) > 0)
//	{
//		if (ft_strcmp(arr, "sa") == 0)
//			printf("Helloworld\n");
//	}
	ft_putchar('s');
	printf("Hello    world");
	return (0);
}