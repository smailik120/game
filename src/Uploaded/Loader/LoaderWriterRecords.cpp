#include "../Loader/LoaderWriterRecords.h"
Writer<string>* LoaderWriterRecords::load() {
    Writer<string>* writerToTable = new Writer<string>("Tables/records.txt");
    return writerToTable;
}