#ifndef IEEE_STRBUF_H
#define IEEE_STRBUF_H

struct strbuf {
	char *buff;
	size_t len;
	size_t alloc;
};

/**
 * Initialize the strbuf. Enough space is allocated for an empty string, so that
 * calls to detach will always return a valid null-terminated string.
 * */
void strbuf_init(struct strbuf *buff);

/**
 * Release any resources under the strbuf. The strbuf MUST be reinitialized for reuse.
 * */
void strbuf_release(struct strbuf *buff);

/**
 * Attach a string to the strbuf, up to buffer_len characters or until null byte
 * is encountered.
 * */
void strbuf_attach(struct strbuf *buff, char *str, size_t buffer_len);

/**
 * Detach the string from the strbuf. The strbuf is reinitialized, and must
 * be strbuf_release()d.
 * */
char *strbuf_detach(struct strbuf *buff);

#endif //IEEE_STRBUF_H
