/** THIS IS AN AUTOMATICALLY GENERATED FILE.
 *  DO NOT MODIFY BY HAND!!
 *
 *  Generated by zcm-gen
 **/

#include <zcm/zcm_coretypes.h>

#ifndef __generic_vec_t_hpp__
#define __generic_vec_t_hpp__

#include <vector>


class generic_vec_t
{
    public:
        int64_t    timestamp;

        int64_t    sequence_num;

        int8_t     data_type;

        int32_t    length;

        std::vector< uint8_t > data;

    public:
        /**
         * Destructs a message properly if anything inherits from it
        */
        virtual ~generic_vec_t() {}

        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline int encode(void* buf, uint32_t offset, uint32_t maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline uint32_t getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to reqad while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline int decode(const void* buf, uint32_t offset, uint32_t maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        inline static int64_t getHash();

        /**
         * Returns "generic_vec_t"
         */
        inline static const char* getTypeName();

        // ZCM support functions. Users should not call these
        inline int      _encodeNoHash(void* buf, uint32_t offset, uint32_t maxlen) const;
        inline uint32_t _getEncodedSizeNoHash() const;
        inline int      _decodeNoHash(const void* buf, uint32_t offset, uint32_t maxlen);
        inline static uint64_t _computeHash(const __zcm_hash_ptr* p);
};

int generic_vec_t::encode(void* buf, uint32_t offset, uint32_t maxlen) const
{
    uint32_t pos = 0;
    int thislen;
    int64_t hash = (int64_t)getHash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    thislen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int generic_vec_t::decode(const void* buf, uint32_t offset, uint32_t maxlen)
{
    uint32_t pos = 0;
    int thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

uint32_t generic_vec_t::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

int64_t generic_vec_t::getHash()
{
    static int64_t hash = _computeHash(NULL);
    return hash;
}

const char* generic_vec_t::getTypeName()
{
    return "generic_vec_t";
}

int generic_vec_t::_encodeNoHash(void* buf, uint32_t offset, uint32_t maxlen) const
{
    uint32_t pos = 0;
    int thislen;

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &this->timestamp, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &this->sequence_num, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    thislen = __int8_t_encode_array(buf, offset + pos, maxlen - pos, &this->data_type, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &this->length, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    if(this->length > 0) {
        thislen = __byte_encode_array(buf, offset + pos, maxlen - pos, &this->data[0], this->length);
        if(thislen < 0) return thislen; else pos += thislen;
    }

    return pos;
}

int generic_vec_t::_decodeNoHash(const void* buf, uint32_t offset, uint32_t maxlen)
{
    uint32_t pos = 0;
    int thislen;

    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this->timestamp, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this->sequence_num, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    thislen = __int8_t_decode_array(buf, offset + pos, maxlen - pos, &this->data_type, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &this->length, 1);
    if(thislen < 0) return thislen; else pos += thislen;

    if(this->length > 0) {
        this->data.resize(this->length);
        thislen = __byte_decode_array(buf, offset + pos, maxlen - pos, &this->data[0], this->length);
        if(thislen < 0) return thislen; else pos += thislen;
    }

    return pos;
}

uint32_t generic_vec_t::_getEncodedSizeNoHash() const
{
    uint32_t enc_size = 0;
    enc_size += __int64_t_encoded_array_size(NULL, 1);
    enc_size += __int64_t_encoded_array_size(NULL, 1);
    enc_size += __int8_t_encoded_array_size(NULL, 1);
    enc_size += __int32_t_encoded_array_size(NULL, 1);
    enc_size += __byte_encoded_array_size(NULL, this->length);
    return enc_size;
}

uint64_t generic_vec_t::_computeHash(const __zcm_hash_ptr*)
{
    uint64_t hash = (uint64_t)0x8b8c72b9a4d71a89LL;
    return (hash<<1) + ((hash>>63)&1);
}

#endif
