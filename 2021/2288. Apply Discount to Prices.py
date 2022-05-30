class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        s = sentence.split(' ')
        res = []
        for w in s:
            if w.startswith('$'):
                price = False
                for c in w[1:]:
                    if not (c >= '0' and c <= '9'):
                        price = False
                        break
                    else:
                        price = True
                if price:
                    p = str(float(w[1:]) * (100 - discount) / 100)
                    while len(p[p.index('.') + 1:]) < 2:
                        p += '0'
                    p = p[:p.index('.') + 3]
                    res.append("$" + str(p))
                else:
                    res.append(w)
            else:
                res.append(w)
        return ' '.join(res)