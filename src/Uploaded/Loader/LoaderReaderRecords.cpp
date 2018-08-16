#include "../Loader/LoaderReaderRecords.h"
Reader<string>* LoaderReaderRecords::load() {
    Reader<string>* readerOfTable = new Reader<string>("Tables/records.txt");
    return readerOfTable;
}