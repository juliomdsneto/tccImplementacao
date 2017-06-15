
int i4_uniform_0i ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    I4_UNIFORM_0I is a portable random integer generator.
//
//  Discussion:
//
//    SEED = ( SEED * 7^5 ) mod (2^31 - 1)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 April 2012
//
//  Parameters:
//
//    Input, int &SEED, the integer "seed" used to generate
//    the output value.  SEED should not be 0.  On output, SEED
//    has been updated.
//
//    Output, int I4_UNIFORM_0I, a uniform random value between
//    1 and 2^31-1.
//
//  Local parameters:
//
//    IA = 7^5
//    IB = 2^15
//    IB16 = 2^16
//    IP = 2^31-1
//
{
  const int ia = 16807;
  const int ib15 = 32768;
  const int ib16 = 65536;
  const int ip = 2147483647;
  int iprhi;
  int ixhi;
  int k;
  int leftlo;
  int loxa;
  int value;
//
//  Don't let SEED be 0.
//
  if ( seed == 0 )
  {
    seed = ip;
  }
//
//  Get the 15 high order bits of SEED2.
//
  ixhi = seed / ib16;
//
//  Get the 16 low bits of SEED and form the low product.
//
  loxa = ( seed - ixhi * ib16 ) * ia;
//
//  Get the 15 high order bits of the low product.
//
  leftlo = loxa / ib16;
//
//  Form the 31 highest bits of the full product.
//
  iprhi = ixhi * ia + leftlo;
//
//  Get overflow past the 31st bit of full product.
//
  k = iprhi / ib15;
//
//  Assemble all the parts and presubtract IP.  The parentheses are
//  essential.
//
  value = ( ( ( loxa - leftlo * ib16 ) - ip ) 
            + ( iprhi - k * ib15 ) * ib16 ) + k;
//
//  Add IP back in if necessary.
//
  if ( value < 0 )
  {
    value = value + ip;
  }
  seed = value;

  return value;
}