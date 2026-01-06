#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct {
	int start;
	int end;
}Meeting;

int compare(const void* a, const void* b)
{
	Meeting* meetingA = (Meeting*)a;
	Meeting* meetingB = (Meeting*)b;
	if (meetingA->end!= meetingB->end) {
		return meetingA->end - meetingB->end;
	} else {
		return meetingA->start - meetingB->start;
	}
}

int main()
{
	int N, i, j, start, end, count = 0;
	Meeting meetings[MAX_SIZE];
	Meeting selected[MAX_SIZE];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &start, &end);
		meetings[i].start = start;
		meetings[i].end = end;
	}
	qsort(meetings, N, sizeof(Meeting), compare);
	end = 0;
	for (i = 0; i < N; i++) 
	{
		if (meetings[i].start >= end) 
		{
			end = meetings[i].end;
			count++;
		}
	}
	printf("%d\n", count);
}