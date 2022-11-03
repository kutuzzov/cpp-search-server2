#include "document.h"
#include "paginator.h"
#include "read_input_functions.h"
#include "string_processing.h"
#include "search_server.h"
#include "request_queue.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    SearchServer search_server("and in at"s);
    RequestQueue request_queue(search_server);

    search_server.AddDocument(1, "curly cat curly tail"s, DocumentStatus::ACTUAL, { 7, 2, 7 });
    search_server.AddDocument(2, "curly dog and fancy collar"s, DocumentStatus::ACTUAL, { 1, 2, 3 });
    search_server.AddDocument(3, "big cat fancy collar "s, DocumentStatus::ACTUAL, { 1, 2, 8 });
    search_server.AddDocument(4, "big dog sparrow Eugene"s, DocumentStatus::ACTUAL, { 1, 3, 2 });
    search_server.AddDocument(5, "big dog sparrow Vasiliy"s, DocumentStatus::ACTUAL, { 1, 1, 1 });

    {
        LOG_DURATION_STREAM("Operation time"s, std::cout);
        MatchDocuments(search_server, "curly -cat"s);
    }
    {
        LOG_DURATION_STREAM("Operation time"s, std::cout);
        FindTopDocuments(search_server, "big -dog"s);
    }

    return 0;
}