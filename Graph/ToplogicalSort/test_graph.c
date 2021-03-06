/****************************************************************
code file	: test_graph.c
code writer	: EOF
code date	: 2014.11.22
e-mail		: jasonleaster@gmail.com

code description:
	
	This test program is used for testing toplogistic sort.

*****************************************************************/
#include "tls.h"

int main()
{
	struct graph* p_graph = NULL;

	FILE* fp = fopen("./text.txt","r+");

	if(!fp)
	{
		printf("fopen() failed!\n");
		return 0;
	}

	int ret    = 0;
	int vertex = 0;
	int edge   = 0;

	int from_v = 0;
	int to_v   = 0;

	fscanf(fp,"%d",&vertex);
	fscanf(fp,"%d",&edge);

	p_graph = init_graph(vertex,edge);

	int temp = 0;
	for(temp;temp < edge;temp++)
	{
		/*
		**	I think it's necessary to check the returned value
		** of scanf() family.
		*/
		ret = fscanf(fp,"%d %d",&from_v,&to_v);
		if(ret != 2)
		{
			break;
		}

		add_edge(p_graph,from_v,to_v);
	}

	struct table* p_table =  init_table(vertex,3);

	printf("Here is the relationship between different vertex\n");
	print_graph(p_graph);

	printf("Aha,the result of toplogistic sort:\n");
	//----------------------
	topsort(p_graph);
	//---------------------

	release_table(p_table);
	release_graph(p_graph);
	fclose(fp);
	return 0;
}
