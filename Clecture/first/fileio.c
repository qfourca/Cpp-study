#include <stdio.h>
int main()
{
    FILE *fp = fopen("file.txt", "w");
    fprintf(fp, "%s %s %d", "I", "am", 20);
    fclose(fp);
    fp = fopen("file.txt", "r");
    char line[100];
    fgets(line, 100, fp);
    printf("%s\n", line);
    return 0;
}
//시간복잡도, 공간복잡도
//시간복잡도:어떤 문제를 해결하는데 걸리는 입력과 시간의 관계
//O(n)이라는 시간복잡도가 있을데 입력 n에 따라 걸리는 시간이 변하는 관계를 설명한다
//일반적으로 O(n^2)이상의 시간복잡도는 사용하기 어렵다
//공간복잡도:어떤 문제를 해결하는데 걸리는 업력과 차지하는 메모리의 관계