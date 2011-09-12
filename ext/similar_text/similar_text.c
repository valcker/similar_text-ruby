#include <ruby.h>
#include <string.h>

static void similar_text_similar_str(const char *txt1, int len1, const char *txt2, int len2, int *pos1, int *pos2, int *max)
{
  char *p, *q;
  char *end1 = (char *) txt1 + len1;
  char *end2 = (char *) txt2 + len2;
  int l;

  *max = 0;
  for (p = (char *) txt1; p < end1; p++) {
    for (q = (char *) txt2; q < end2; q++) {
      for (l = 0; (p + l < end1) && (q + l < end2) && (p[l] == q[l]); l++);
      if (l > *max) {
        *max = l;
        *pos1 = p - txt1;
        *pos2 = q - txt2;
      }
    }
  }
}

static int similar_text_similar_char(const char *txt1, int len1, const char *txt2, int len2)
{
  int sum;
  int pos1, pos2, max;

  similar_text_similar_str(txt1, len1, txt2, len2, &pos1, &pos2, &max);
  if ((sum = max)) {
    if (pos1 && pos2) {
      sum += similar_text_similar_char(txt1, pos1,
          txt2, pos2);
    }
    if ((pos1 + max < len1) && (pos2 + max < len2)) {
      sum += similar_text_similar_char(txt1 + pos1 + max, len1 - pos1 - max,
          txt2 + pos2 + max, len2 - pos2 - max);
    }
  }

  return sum;
}

int similar_text(const char *txt1, const char *txt2, double *percent)
{
  size_t t1_len, t2_len;
  int sim;

  t1_len = strlen(txt1);
  t2_len = strlen(txt2);

  sim = similar_text_similar_char(txt1, t1_len, txt2, t2_len);
  *percent = sim * 200.0 / (t1_len + t2_len);

  return sim;
}

static VALUE t_similar(VALUE str1, VALUE str2)
{
  double percent;

  similar_text(StringValueCStr(str1), StringValueCStr(str2), &percent);

  return rb_float_new(percent);
}

static VALUE t_similar_bool(VALUE str1, VALUE str2)
{
  double percent;

  similar_text(StringValueCStr(str1), StringValueCStr(str2), &percent);

  if (percent == 100.0) {
    return Qtrue;
  }
  else {
    return Qfalse;
  }
}

void Init_similar_text()
{
  rb_cString = rb_define_class("String", rb_cObject);
  rb_define_method(rb_cString, "similar", t_similar, 1);
  rb_define_method(rb_cString, "similar?", t_similar_bool, 1);
}

