#include "proxy.h"
#include "test.h"

#include <cassert>

extern "C" {
#include "ascii_2_base64.h"
}

static void test_1() {
    std::string output;

    {
        std::string input = "Give someone a program, you frustrate them for a day; teach them how to program, you frustrate them for a lifetime. - David Leinweber";
        Proxy proxy(input);
        ascii_2_base64();
        output = proxy.output();
    }

    std::string expect = "R2l2ZSBzb21lb25lIGEgcHJvZ3JhbSwgeW91IGZydXN0cmF0ZSB0aGVtIGZvciBhIGRheTsgdGVhY2ggdGhlbSBob3cgdG8gcHJvZ3JhbSwgeW91IGZydXN0cmF0ZSB0aGVtIGZvciBhIGxpZmV0aW1lLiAtIERhdmlkIExlaW53ZWJlcg==";
    ASSERT_EQ(expect, output);
}

static void test_2() {
    std::string output;

    {
        std::string input = "Programming isn't about what you know; it's about what you can figure out. - Chris Pine";
        Proxy proxy(input);
        ascii_2_base64();
        output = proxy.output();
    }

    std::string expect = "UHJvZ3JhbW1pbmcgaXNuJ3QgYWJvdXQgd2hhdCB5b3Uga25vdzsgaXQncyBhYm91dCB3aGF0IHlvdSBjYW4gZmlndXJlIG91dC4gLSBDaHJpcyBQaW5l";
    ASSERT_EQ(expect, output);
}

static void test_3() {
    std::string output;

    {
        std::string input = "Every great developer you know got there by solving problems they were unqualified to solve\nuntil they actually did it. - Patrick McKenzie";
        Proxy proxy(input);
        ascii_2_base64();
        output = proxy.output();
    }

    std::string expect = "RXZlcnkgZ3JlYXQgZGV2ZWxvcGVyIHlvdSBrbm93IGdvdCB0aGVyZSBieSBzb2x2aW5nIHByb2JsZW1zIHRoZXkgd2VyZSB1bnF1YWxpZmllZCB0byBzb2x2ZQp1bnRpbCB0aGV5IGFjdHVhbGx5IGRpZCBpdC4gLSBQYXRyaWNrIE1jS2Vuemll";
    ASSERT_EQ(expect, output);
}

static void test_4() {
    std::string output;

    {
        std::string input = "Do not go gentle into that good night,\n"
                            "Old age should burn and rave at close of day;\n"
                            "Rage, rage against the dying of the light.\n"
                            "\n"
                            "Though wise men at their end know dark is right,\n"
                            "Because their words had forked no lightning they\n"
                            "Do not go gentle into that good night.\n"
                            "\n"
                            "Good men, the last wave by, crying how bright\n"
                            "Their frail deeds might have danced in a green bay,\n"
                            "Rage, rage against the dying of the light.\n"
                            "\n"
                            "Wild men who caught and sang the sun in flight,\n"
                            "And learn, too late, they grieved it on its way,\n"
                            "Do not go gentle into that good night.\n"
                            "\n"
                            "Grave men, near death, who see with blinding sight\n"
                            "Blind eyes could blaze like meteors and be gay,\n"
                            "Rage, rage against the dying of the light.\n"
                            "\n"
                            "And you, my father, there on the sad height,\n"
                            "Curse, bless, me now with your fierce tears, I pray.\n"
                            "Do not go gentle into that good night.\n"
                            "Rage, rage against the dying of the light.\n"
                            "\n"
                            "- Dylan Thomas";
        Proxy proxy(input);
        ascii_2_base64();
        output = proxy.output();
    }

    std::string expect = "RG8gbm90IGdvIGdlbnRsZSBpbnRvIHRoYXQgZ29vZCBuaWdodCwKT2xkIGFnZSBzaG91bGQgYnVybiBhbmQgcmF2ZSBhdCBjbG9zZSBvZiBkYXk7ClJhZ2UsIHJhZ2UgYWdhaW5zdCB0aGUgZHlpbmcgb2YgdGhlIGxpZ2h0LgoKVGhvdWdoIHdpc2UgbWVuIGF0IHRoZWlyIGVuZCBrbm93IGRhcmsgaXMgcmlnaHQsCkJlY2F1c2UgdGhlaXIgd29yZHMgaGFkIGZvcmtlZCBubyBsaWdodG5pbmcgdGhleQpEbyBub3QgZ28gZ2VudGxlIGludG8gdGhhdCBnb29kIG5pZ2h0LgoKR29vZCBtZW4sIHRoZSBsYXN0IHdhdmUgYnksIGNyeWluZyBob3cgYnJpZ2h0ClRoZWlyIGZyYWlsIGRlZWRzIG1pZ2h0IGhhdmUgZGFuY2VkIGluIGEgZ3JlZW4gYmF5LApSYWdlLCByYWdlIGFnYWluc3QgdGhlIGR5aW5nIG9mIHRoZSBsaWdodC4KCldpbGQgbWVuIHdobyBjYXVnaHQgYW5kIHNhbmcgdGhlIHN1biBpbiBmbGlnaHQsCkFuZCBsZWFybiwgdG9vIGxhdGUsIHRoZXkgZ3JpZXZlZCBpdCBvbiBpdHMgd2F5LApEbyBub3QgZ28gZ2VudGxlIGludG8gdGhhdCBnb29kIG5pZ2h0LgoKR3JhdmUgbWVuLCBuZWFyIGRlYXRoLCB3aG8gc2VlIHdpdGggYmxpbmRpbmcgc2lnaHQKQmxpbmQgZXllcyBjb3VsZCBibGF6ZSBsaWtlIG1ldGVvcnMgYW5kIGJlIGdheSwKUmFnZSwgcmFnZSBhZ2FpbnN0IHRoZSBkeWluZyBvZiB0aGUgbGlnaHQuCgpBbmQgeW91LCBteSBmYXRoZXIsIHRoZXJlIG9uIHRoZSBzYWQgaGVpZ2h0LApDdXJzZSwgYmxlc3MsIG1lIG5vdyB3aXRoIHlvdXIgZmllcmNlIHRlYXJzLCBJIHByYXkuCkRvIG5vdCBnbyBnZW50bGUgaW50byB0aGF0IGdvb2QgbmlnaHQuClJhZ2UsIHJhZ2UgYWdhaW5zdCB0aGUgZHlpbmcgb2YgdGhlIGxpZ2h0LgoKLSBEeWxhbiBUaG9tYXM=";
    ASSERT_EQ(expect, output);
}


int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    return EXIT_SUCCESS;
}
