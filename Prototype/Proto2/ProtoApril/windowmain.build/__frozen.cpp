// This provides the frozen (compiled bytecode) files that are included if
// any.
#include <Python.h>

#include "nuitka/constants_blob.h"

// Blob from which modules are unstreamed.
#define stream_data constant_bin

// These modules should be loaded as bytecode. They may e.g. have to be loadable
// during "Py_Initialize" already, or for irrelevance, they are only included
// in this un-optimized form. These are not compiled by Nuitka, and therefore
// are not accelerated at all, merely bundled with the binary or module, so
// that CPython library can start out finding them.

struct frozen_desc {
    char const *name;
    ssize_t start;
    int size;
};

void copyFrozenModulesTo( struct _frozen *destination )
{
    struct frozen_desc frozen_modules[] = {
        {"_collections_abc", 6496436, 28764},
        {"_compression", 6525200, 4169},
        {"_weakrefset", 6529369, 7623},
        {"abc", 6536992, 5357},
        {"base64", 6542349, 17094},
        {"bz2", 6559443, 11468},
        {"codecs", 6570911, 33936},
        {"collections", 6604847, -46458},
        {"collections.abc", 6496436, 28764},
        {"copyreg", 6651305, 4341},
        {"dis", 6655646, 15825},
        {"encodings", 6671471, -3926},
        {"encodings.aliases", 6675397, 6353},
        {"encodings.ascii", 6681750, 1904},
        {"encodings.base64_codec", 6683654, 2422},
        {"encodings.big5", 6686076, 1432},
        {"encodings.big5hkscs", 6687508, 1442},
        {"encodings.bz2_codec", 6688950, 3313},
        {"encodings.charmap", 6692263, 2914},
        {"encodings.cp037", 6695177, 2445},
        {"encodings.cp1006", 6697622, 2521},
        {"encodings.cp1026", 6700143, 2449},
        {"encodings.cp1125", 6702592, 8152},
        {"encodings.cp1140", 6710744, 2435},
        {"encodings.cp1250", 6713179, 2472},
        {"encodings.cp1251", 6715651, 2469},
        {"encodings.cp1252", 6718120, 2472},
        {"encodings.cp1253", 6720592, 2485},
        {"encodings.cp1254", 6723077, 2474},
        {"encodings.cp1255", 6725551, 2493},
        {"encodings.cp1256", 6728044, 2471},
        {"encodings.cp1257", 6730515, 2479},
        {"encodings.cp1258", 6732994, 2477},
        {"encodings.cp273", 6735471, 2431},
        {"encodings.cp424", 6737902, 2475},
        {"encodings.cp437", 6740377, 7869},
        {"encodings.cp500", 6748246, 2445},
        {"encodings.cp720", 6750691, 2542},
        {"encodings.cp737", 6753233, 8191},
        {"encodings.cp775", 6761424, 7899},
        {"encodings.cp850", 6769323, 7530},
        {"encodings.cp852", 6776853, 7907},
        {"encodings.cp855", 6784760, 8160},
        {"encodings.cp856", 6792920, 2507},
        {"encodings.cp857", 6795427, 7510},
        {"encodings.cp858", 6802937, 7500},
        {"encodings.cp860", 6810437, 7848},
        {"encodings.cp861", 6818285, 7863},
        {"encodings.cp862", 6826148, 8052},
        {"encodings.cp863", 6834200, 7863},
        {"encodings.cp864", 6842063, 8007},
        {"encodings.cp865", 6850070, 7863},
        {"encodings.cp866", 6857933, 8196},
        {"encodings.cp869", 6866129, 7887},
        {"encodings.cp874", 6874016, 2573},
        {"encodings.cp875", 6876589, 2442},
        {"encodings.cp932", 6879031, 1434},
        {"encodings.cp949", 6880465, 1434},
        {"encodings.cp950", 6881899, 1434},
        {"encodings.euc_jis_2004", 6883333, 1448},
        {"encodings.euc_jisx0213", 6884781, 1448},
        {"encodings.euc_jp", 6886229, 1436},
        {"encodings.euc_kr", 6887665, 1436},
        {"encodings.gb18030", 6889101, 1438},
        {"encodings.gb2312", 6890539, 1436},
        {"encodings.gbk", 6891975, 1430},
        {"encodings.hex_codec", 6893405, 2409},
        {"encodings.hp_roman8", 6895814, 2646},
        {"encodings.hz", 6898460, 1428},
        {"encodings.idna", 6899888, 5640},
        {"encodings.iso2022_jp", 6905528, 1449},
        {"encodings.iso2022_jp_1", 6906977, 1453},
        {"encodings.iso2022_jp_2", 6908430, 1453},
        {"encodings.iso2022_jp_2004", 6909883, 1459},
        {"encodings.iso2022_jp_3", 6911342, 1453},
        {"encodings.iso2022_jp_ext", 6912795, 1457},
        {"encodings.iso2022_kr", 6914252, 1449},
        {"encodings.iso8859_1", 6915701, 2444},
        {"encodings.iso8859_10", 6918145, 2449},
        {"encodings.iso8859_11", 6920594, 2543},
        {"encodings.iso8859_13", 6923137, 2452},
        {"encodings.iso8859_14", 6925589, 2470},
        {"encodings.iso8859_15", 6928059, 2449},
        {"encodings.iso8859_16", 6930508, 2451},
        {"encodings.iso8859_2", 6932959, 2444},
        {"encodings.iso8859_3", 6935403, 2451},
        {"encodings.iso8859_4", 6937854, 2444},
        {"encodings.iso8859_5", 6940298, 2445},
        {"encodings.iso8859_6", 6942743, 2489},
        {"encodings.iso8859_7", 6945232, 2452},
        {"encodings.iso8859_8", 6947684, 2483},
        {"encodings.iso8859_9", 6950167, 2444},
        {"encodings.johab", 6952611, 1434},
        {"encodings.koi8_r", 6954045, 2496},
        {"encodings.koi8_t", 6956541, 2407},
        {"encodings.koi8_u", 6958948, 2482},
        {"encodings.kz1048", 6961430, 2459},
        {"encodings.latin_1", 6963889, 1916},
        {"encodings.mac_arabic", 6965805, 7763},
        {"encodings.mac_centeuro", 6973568, 2483},
        {"encodings.mac_croatian", 6976051, 2491},
        {"encodings.mac_cyrillic", 6978542, 2481},
        {"encodings.mac_farsi", 6981023, 2425},
        {"encodings.mac_greek", 6983448, 2465},
        {"encodings.mac_iceland", 6985913, 2484},
        {"encodings.mac_latin2", 6988397, 2625},
        {"encodings.mac_roman", 6991022, 2482},
        {"encodings.mac_romanian", 6993504, 2492},
        {"encodings.mac_turkish", 6995996, 2485},
        {"encodings.mbcs", 6998481, 1734},
        {"encodings.oem", 7000215, 1547},
        {"encodings.palmos", 7001762, 2472},
        {"encodings.ptcp154", 7004234, 2566},
        {"encodings.punycode", 7006800, 6334},
        {"encodings.quopri_codec", 7013134, 2438},
        {"encodings.raw_unicode_escape", 7015572, 1785},
        {"encodings.rot_13", 7017357, 3024},
        {"encodings.shift_jis", 7020381, 1442},
        {"encodings.shift_jis_2004", 7021823, 1452},
        {"encodings.shift_jisx0213", 7023275, 1452},
        {"encodings.tis_620", 7024727, 2534},
        {"encodings.undefined", 7027261, 2118},
        {"encodings.unicode_escape", 7029379, 1765},
        {"encodings.utf_16", 7031144, 4895},
        {"encodings.utf_16_be", 7036039, 1673},
        {"encodings.utf_16_le", 7037712, 1673},
        {"encodings.utf_32", 7039385, 4788},
        {"encodings.utf_32_be", 7044173, 1566},
        {"encodings.utf_32_le", 7045739, 1566},
        {"encodings.utf_7", 7047305, 1594},
        {"encodings.utf_8", 7048899, 1653},
        {"encodings.utf_8_sig", 7050552, 4569},
        {"encodings.uu_codec", 7055121, 3272},
        {"encodings.zlib_codec", 7058393, 3132},
        {"enum", 7061525, 24422},
        {"functools", 7085947, 27920},
        {"genericpath", 7113867, 4024},
        {"heapq", 7117891, 14093},
        {"importlib", 7131984, -3781},
        {"importlib._bootstrap", 7135765, 28628},
        {"importlib._bootstrap_external", 7164393, 43733},
        {"importlib.machinery", 7208126, 985},
        {"inspect", 7209111, 80406},
        {"io", 26409, 3477},
        {"keyword", 7289517, 1021},
        {"linecache", 7290538, 3862},
        {"locale", 7294400, 34712},
        {"ntpath", 94780, 14680},
        {"opcode", 7329112, 5443},
        {"operator", 7334555, 13714},
        {"os", 109460, 31420},
        {"quopri", 7348269, 5771},
        {"re", 140880, 14331},
        {"reprlib", 7354040, 5326},
        {"sre_compile", 7359366, 15165},
        {"sre_constants", 7374531, 6382},
        {"sre_parse", 7380913, 21670},
        {"stat", 7402583, 4395},
        {"stringprep", 7406978, 11040},
        {"struct", 7418018, 353},
        {"threading", 7418371, 39952},
        {"token", 7458323, 2508},
        {"tokenize", 7460831, 17183},
        {"types", 7478014, 9200},
        {"warnings", 7487214, 13675},
        {NULL, 0, 0}
    };

    struct frozen_desc *current = frozen_modules;

    for(;;)
    {
        destination->name = (char *)current->name;
        destination->code = (unsigned char *)&constant_bin[ current->start ];
        destination->size = current->size;

        if (destination->name == NULL) break;

        current += 1;
        destination += 1;
    };
}
