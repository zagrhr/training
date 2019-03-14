#include <stdio.h>
#include "commonType.h"
#include "initAndTerm.h"
#include "dataControl.h"

#define TOT_MENU_CNT 4

int getSelection(void){
	int selectNum = 0;
	printf("\n");
	printf("1. 출력\n");
	printf("2. 입력\n");
	printf("3. 삭제\n");
	printf("4. 종료\n");
	printf("메뉴선택:");
	scanf("%d", &selectNum);
	while(getchar() != '\n');
	return selectNum;
}

int main(int argc, char* argv[]){
	int selNum = 0;
	Node* root = NULL;
	void (*pF[TOT_MENU_CNT])(Node**) = {selectPrint, selectInsert
			, selectDelete, selectEnd};
	int res = -1;
	while(selNum != TOT_MENU_CNT){
		selNum = getSelection();
		if(selNum > 0 && selNum < (TOT_MENU_CNT+1) ){
			exeFunc(pF, (selNum-1), &root, &res);
			printf("실행결과:%d\n", res);
		}else{
			printf("다시 선택하세요.\n");
			continue;
		}
	}
	return 0;
}
