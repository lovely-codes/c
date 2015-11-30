#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t readpos = 0;
size_t writedata( void *ptr, size_t size, size_t nmemb, void *stream) {
	memcpy(stream + readpos ,ptr,size * nmemb);
	readpos += size * nmemb;
	return size * nmemb;
}

int main(int argc,char** argv){
	char *data = (char*)malloc(sizeof(char)*102400);
	CURL *curl;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
	curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,writedata);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,data);
	curl_easy_perform(curl);
	return 0;
}
