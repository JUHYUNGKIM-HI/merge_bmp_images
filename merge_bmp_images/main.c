//
//  main.c
//  merge_bmp_images
//
//  Created by 김주형 on 2021/09/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "windows.h"

#define WIDTHBYTES(bits) (((bits) + 31) / 32 * 4) // 각 행은 반드시 4bytes의 배수이다.

typedef unsigned char BYTE;

int main()
{
    FILE *file, *file1, *file2, *file3, *file4; // 파일 포인터
    BITMAPFILEHEADER hf; // 비트맵 파일 헤더
    BITMAPINFOHEADER hInfo; // 비트맵 정보 헤더
    int rwsize, out_rwsize; // 라인 당 바이트 수
    BYTE *inPutImg1, *inPutImg2, *inPutImg3, *inPutImg4; // 입력 이미지 포인터
    BYTE *outPutImg; // 출력 데이터 포인터
    int x, y;
    
    // 1.bmp 입력 영상 파일을 연다.
    file1 = fopen("/Users/juhyung/Desktop/merge_bmp_images/images/1.bmp", "rb");
    if(file1 == NULL){
        printf("1.bmp 파일이 없습니다!\n");
        return -1;
    }
    
    fread(&hf, sizeof(BITMAPFILEHEADER), 1, file1); // 파일 헤더 읽음
    if(hf.bfType != 0x4D42) // BMP 포맷('BM') 인지를 확인
        return -1;
    
    fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, file1); // 비트맵 정보 헤더 읽음
    
    // 24bit 영상만 입력으로 받음
    if(hInfo.biBitCount != 24){
        printf("bit수가 다른 파일입니다!\n");
        return  -1;
    }
    
    // 2.bmp 입력 영상 파일을 연다.
    file2 = fopen("/Users/juhyung/Desktop/merge_bmp_images/images/2.bmp", "rb");
    if(file2 == NULL){
        printf("2.bmp 파일이 없습니다!\n");
        return -1;
    }
    
    fread(&hf, sizeof(BITMAPFILEHEADER), 1, file2); // 파일 헤더 읽음
    if(hf.bfType != 0x4D42) // BMP 포맷('BM') 인지를 확인
        return -1;
    
    fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, file2); // 비트맵 정보 헤더 읽음
    
    // 24bit 영상만 입력으로 받음
    if(hInfo.biBitCount != 24){
        printf("bit수가 다른 파일입니다!\n");
        return  -1;
    }
    
    // 3.bmp 입력 영상 파일을 연다.
    file3 = fopen("/Users/juhyung/Desktop/merge_bmp_images/images/3.bmp", "rb");
    if(file3 == NULL){
        printf("3.bmp 파일이 없습니다!\n");
        return -1;
    }
    
    fread(&hf, sizeof(BITMAPFILEHEADER), 1, file3); // 파일 헤더 읽음
    if(hf.bfType != 0x4D42) // BMP 포맷('BM') 인지를 확인
        return -1;
    
    fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, file3); // 비트맵 정보 헤더 읽음
    
    // 24bit 영상만 입력으로 받음
    if(hInfo.biBitCount != 24){
        printf("bit수가 다른 파일입니다!\n");
        return  -1;
    }
    
    // 3.bmp 입력 영상 파일을 연다.
    file4 = fopen("/Users/juhyung/Desktop/merge_bmp_images/images/4.bmp", "rb");
    if(file4 == NULL){
        printf("4.bmp 파일이 없습니다!\n");
        return -1;
    }
    
    fread(&hf, sizeof(BITMAPFILEHEADER), 1, file4); // 파일 헤더 읽음
    if(hf.bfType != 0x4D42) // BMP 포맷('BM') 인지를 확인
        return -1;
    
    fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, file4); // 비트맵 정보 헤더 읽음
    
    // 24bit 영상만 입력으로 받음
    if(hInfo.biBitCount != 24){
        printf("bit수가 다른 파일입니다!\n");
        return  -1;
    }
    
    // 입출력 데이터를 위한 라인 당 바이트 수 계산
    rwsize = WIDTHBYTES(24 * hInfo.biWidth); // 입력 영상
    out_rwsize = WIDTHBYTES(24 * hInfo.biWidth * 2); // 출력 영상
    
    // 1.bmp 비트맵 데이터가 시작되는 위치로 파일 포인터를 이동
    fseek(file1, hf.bfOffBits, SEEK_SET);
    // 입력 영상 데이터를 위한 메모리 할당
    inPutImg1 = (BYTE*)malloc(rwsize * hInfo.biHeight);
    // 영상 데이터를 입력 영상으로 부터 읽음
    fread(inPutImg1, sizeof(char), rwsize * hInfo.biHeight, file1);
    fclose(file1);
    
    // 2.bmp 비트맵 데이터가 시작되는 위치로 파일 포인터를 이동
    fseek(file2, hf.bfOffBits, SEEK_SET);
    // 입력 영상 데이터를 위한 메모리 할당
    inPutImg2 = (BYTE*)malloc(rwsize * hInfo.biHeight);
    // 영상 데이터를 입력 영상으로 부터 읽음
    fread(inPutImg2, sizeof(char), rwsize * hInfo.biHeight, file2);
    fclose(file2);
    
    // 3.bmp 비트맵 데이터가 시작되는 위치로 파일 포인터를 이동
    fseek(file3, hf.bfOffBits, SEEK_SET);
    // 입력 영상 데이터를 위한 메모리 할당
    inPutImg3 = (BYTE*)malloc(rwsize * hInfo.biHeight);
    // 영상 데이터를 입력 영상으로 부터 읽음
    fread(inPutImg3, sizeof(char), rwsize * hInfo.biHeight, file3);
    fclose(file3);
    
    // 4.bmp 비트맵 데이터가 시작되는 위치로 파일 포인터를 이동
    fseek(file4, hf.bfOffBits, SEEK_SET);
    // 입력 영상 데이터를 위한 메모리 할당
    inPutImg4 = (BYTE*)malloc(rwsize * hInfo.biHeight);
    // 영상 데이터를 입력 영상으로 부터 읽음
    fread(inPutImg4, sizeof(char), rwsize * hInfo.biHeight, file4);
    fclose(file4);
    
    // 출력 영상 데이터를 위한 메모리 할당
    outPutImg = (BYTE*)malloc(out_rwsize * hInfo.biHeight * 2);
    
    // 3분면 - 3.bmp
    for(y = 0; y < 300; y++){
        for(x = 0; x < 400 * 3; x++){
            outPutImg[y * out_rwsize + x + 2] = inPutImg3[y * rwsize + x + 2]; // R
            outPutImg[y * out_rwsize + x + 1] = inPutImg3[y * rwsize + x + 1]; // G
            outPutImg[y * out_rwsize + x + 0] = inPutImg3[y * rwsize + x + 0]; // B
        }
    }
    
    // 4분면 - 4.bmp
    for(y = 0; y < 300; y++){
        for(x = 0; x < 400 * 3; x++){
            outPutImg[y * out_rwsize + x + 2 + 1200] = inPutImg4[y * rwsize + x + 2]; // R
            outPutImg[y * out_rwsize + x + 1 + 1200] = inPutImg4[y * rwsize + x + 1]; // G
            outPutImg[y * out_rwsize + x + 0 + 1200] = inPutImg4[y * rwsize + x + 0]; // B
        }
    }
    
    // 2분면 - 1.bmp
    for(y = 0; y < 300; y++){
        for(x = 0; x < 400 * 3; x++){
            outPutImg[(y + 300)  * out_rwsize + x + 2] = inPutImg1[y * rwsize + x + 2]; // R
            outPutImg[(y + 300) * out_rwsize + x + 1] = inPutImg1[y * rwsize + x + 1]; // G
            outPutImg[(y + 300) * out_rwsize + x + 0] = inPutImg1[y * rwsize + x + 0]; // B
        }
    }
    
    // 1분면 - 2.bmp
    for(y = 0; y < 300; y++){
        for(x = 0; x < 400 * 3; x++){
            outPutImg[(y + 300)  * out_rwsize + x + 2 + 1200] = inPutImg2[y * rwsize + x + 2]; // R
            outPutImg[(y + 300) * out_rwsize + x + 1 + 1200] = inPutImg2[y * rwsize + x + 1]; // G
            outPutImg[(y + 300) * out_rwsize + x + 0 + 1200] = inPutImg2[y * rwsize + x + 0]; // B
        }
    }
    
    // 출력 영상의 정보
    hInfo.biWidth = 800; // 영상의 가로 길이
    hInfo.biHeight = 600; // 영상의 세로 길이
    hInfo.biBitCount = 24;
    hInfo.biSizeImage = out_rwsize * hInfo.biHeight * 2;
    hInfo.biClrUsed = hInfo.biClrImportant = 0;
    hf.bfOffBits = 54;
    hf.bfSize = hf.bfOffBits + hInfo.biSizeImage;
    
    file = fopen("/Users/juhyung/Desktop/merge_bmp_images/result.bmp", "wb");
    
    fwrite(&hf, sizeof(char), sizeof(BITMAPFILEHEADER), file);
    fwrite(&hInfo, sizeof(char), sizeof(BITMAPINFOHEADER), file);
    fwrite(outPutImg, sizeof(char), out_rwsize * hInfo.biHeight, file);
    
    fclose(file);
    
    // 메모리 해제
    free(outPutImg);
    free(inPutImg1);
    free(inPutImg2);
    free(inPutImg3);
    free(inPutImg4);
    
    return 0;
    
}
