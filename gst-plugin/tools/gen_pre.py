from charm.schemes.prenc.pre_afgh06_temp_jm import AFGH06Temp
from charm.core.engine.util import objectToBytes
from charm.toolbox.pairinggroup import PairingGroup

group = PairingGroup('SS512')
scheme = AFGH06Temp(group)
params = scheme.setup()

pk_a, sk_a = scheme.keygen(params)
pk_b, sk_b = scheme.keygen(params)
pk_c, sk_c = scheme.keygen(params)
pk_d, sk_d = scheme.keygen(params)

rk_ab_2018 = scheme.re_keygen(params, sk_a, pk_b, l='2018')
rk_ab_2017 = scheme.re_keygen(params, sk_a, pk_b, l='2017')
rk_ac_2018 = scheme.re_keygen(params, sk_a, pk_c, l='2018')

i = ord('A')
for pk, sk in [(pk_a, sk_a), (pk_b, sk_b), (pk_c, sk_c), (pk_d, sk_d)]:
    print("PK_" + chr(i) + ':', objectToBytes(pk, group))
    print("SK_" + chr(i) + ':', objectToBytes(sk, group))
    i += 1
for rk, a, b, t in [(rk_ab_2018, 'A', 'B', '2018'), (rk_ab_2017, 'A', 'B', '2017'), (rk_ab_2018, 'A', 'C', '2018')]:
    print('RK_' + a + '->' + b + '_' + t + ':', objectToBytes(rk, group))
