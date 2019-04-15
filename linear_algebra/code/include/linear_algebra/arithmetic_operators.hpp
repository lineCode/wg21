#ifndef LINEAR_ALGEBRA_ARITHMETIC_OPERATORS_HPP_DEFINED
#define LINEAR_ALGEBRA_ARITHMETIC_OPERATORS_HPP_DEFINED

namespace STD_LA {
//=================================================================================================
//  Unary negation operators, which forward to the negation traits to do the work.
//=================================================================================================
//
template<class ET1, class OT1>
inline auto
operator -(vector<ET1, OT1> const& v1)
{
    using op1_type   = vector<ET1, OT1>;
    using op_traits  = OT1;
    using neg_traits = typename OT1::template negation_traits<op1_type, op_traits>;

    return neg_traits::negate(v1);
}

template<class ET1, class OT1>
inline auto
operator -(matrix<ET1, OT1> const& m1)
{
    using op1_type   = matrix<ET1, OT1>;
    using op_traits  = OT1;
    using neg_traits = typename OT1::template negation_traits<op1_type, op_traits>;

    return neg_traits::negate(m1);
}


//=================================================================================================
//  Binary addition operators, which forward to the addition traits to do the work.
//=================================================================================================
//
template<class ET1, class OT1, class ET2, class OT2>
inline auto
operator +(vector<ET1, OT1> const& v1, vector<ET2, OT2> const& v2)
{
    using op_traits  = matrix_operation_traits_selector_t<OT1, OT2>;
    using op1_type   = vector<ET1, OT1>;
    using op2_type   = vector<ET2, OT2>;
    using add_traits = detail::addition_traits_t<op_traits, op1_type, op2_type>;

    return add_traits::add(v1, v2);
}

template<class ET1, class OT1, class ET2, class OT2>
inline auto
operator +(matrix<ET1, OT1> const& m1, matrix<ET2, OT2> const& m2)
{
    using op_traits  = matrix_operation_traits_selector_t<OT1, OT2>;
    using op1_type   = matrix<ET1, OT1>;
    using op2_type   = matrix<ET2, OT2>;
    using add_traits = detail::addition_traits_t<op_traits, op1_type, op2_type>;

    return add_traits::add(m1, m2);
}


//=================================================================================================
//  Binary subtraction operators, which forward to the subtraction traits to do the work.
//=================================================================================================
//
template<class ET1, class OT1, class ET2, class OT2>
inline auto
operator -(vector<ET1, OT1> const& v1, vector<ET2, OT2> const& v2)
{
    using op_traits  = matrix_operation_traits_selector_t<OT1, OT2>;
    using op1_type   = vector<ET1, OT1>;
    using op2_type   = vector<ET2, OT2>;
    using sub_traits = typename op_traits::template subtraction_traits<op1_type, op2_type, op_traits>;

    return sub_traits::subtract(v1, v2);
}

template<class ET1, class OT1, class ET2, class OT2>
inline auto
operator -(matrix<ET1, OT1> const& m1, matrix<ET2, OT2> const& m2)
{
    using op_traits  = matrix_operation_traits_selector_t<OT1, OT2>;
    using op1_type   = matrix<ET1, OT1>;
    using op2_type   = matrix<ET2, OT2>;
    using sub_traits = typename op_traits::template subtraction_traits<op1_type, op2_type, op_traits>;

    return sub_traits::subtract(m1, m2);
}

//=================================================================================================
//  Multiplication operators, which forward to the multiplication traits to do the work.
//=================================================================================================
//- vector*scalar
//
template<class ET1, class OT1, class S2>
inline auto
operator *(vector<ET1, OT1> const& v1, S2 s2)
{
    static_assert(is_matrix_element_v<S2>);

    using op_traits  = OT1;
    using op1_type   = vector<ET1, OT1>;
    using op2_type   = S2;
    using mul_traits = typename op_traits::template multiplication_traits<op1_type, op2_type, op_traits>;

    return mul_traits::multiply(v1, s2);
}

template<class S1, class ET2, class OT2>
inline auto
operator *(S1 s1, vector<ET2, OT2> const& v2)
{
    static_assert(is_matrix_element_v<S1>);

    using op_traits  = OT2;
    using op1_type   = S1;
    using op2_type   = vector<ET2, OT2>;
    using mul_traits = typename op_traits::template multiplication_traits<op1_type, op2_type, op_traits>;

    return mul_traits::multiply(s1, v2);
}

//---------------
//- matrix*scalar
//
template<class ET1, class OT1, class S2>
inline auto
operator *(matrix<ET1, OT1> const& m1, S2 s2)
{
    static_assert(is_matrix_element_v<S2>);

    using op_traits  = OT1;
    using op1_type   = matrix<ET1, OT1>;
    using op2_type   = S2;
    using mul_traits = typename op_traits::template multiplication_traits<op1_type, op2_type, op_traits>;

    return mul_traits::multiply(m1, s2);
}

template<class S1, class ET2, class OT2>
inline auto
operator *(S1 s1, matrix<ET2, OT2> const& m2)
{
    static_assert(is_matrix_element_v<S1>);

    using op_traits  = OT2;
    using op1_type   = S1;
    using op2_type   = matrix<ET2, OT2>;
    using mul_traits = typename op_traits::template multiplication_traits<op2_type, op1_type, op_traits>;

    return mul_traits::multiply(m2, s1);
}

//---------------
//- vector*vector
//
template<class ET1, class OT1, class ET2, class OT2>
inline auto
operator *(vector<ET1, OT1> const& v1, vector<ET2, OT2> const& v2)
{
    using op_traits  = matrix_operation_traits_selector_t<OT1, OT2>;
    using op1_type   = vector<ET1, OT1>;
    using op2_type   = vector<ET2, OT2>;
    using mul_traits = typename op_traits::template multiplication_traits<op1_type, op2_type, op_traits>;

    return mul_traits::multiply(v1, v2);
}

//---------------
//- matrix*vector
//
template<class ET1, class OT1, class ET2, class OT2>
inline auto
operator *(matrix<ET1, OT1> const& m1, vector<ET2, OT2> const& v2)
{
    using op_traits  = matrix_operation_traits_selector_t<OT1, OT2>;
    using op1_type   = matrix<ET1, OT1>;
    using op2_type   = vector<ET2, OT2>;
    using mul_traits = typename op_traits::template multiplication_traits<op1_type, op2_type, op_traits>;

    return mul_traits::multiply(m1, v2);
}

//---------------
//- vector*matrix
//
template<class ET1, class OT1, class ET2, class OT2>
inline auto
operator *(vector<ET1, OT1> const& v1, matrix<ET2, OT2> const& m2)
{
    using op_traits  = matrix_operation_traits_selector_t<OT1, OT2>;
    using op1_type   = vector<ET1, OT1>;
    using op2_type   = matrix<ET2, OT2>;
    using mul_traits = typename op_traits::template multiplication_traits<op1_type, op2_type, op_traits>;

    return mul_traits::multiply(v1, m2);
}

//---------------
//- matrix*matrix
//
template<class ET1, class OT1, class ET2, class OT2>
inline auto
operator *(matrix<ET1, OT1> const& m1, matrix<ET2, OT2> const& m2)
{
    using op_traits  = matrix_operation_traits_selector_t<OT1, OT2>;
    using op1_type   = matrix<ET1, OT1>;
    using op2_type   = matrix<ET2, OT2>;
    using mul_traits = typename op_traits::template multiplication_traits<op1_type, op2_type, op_traits>;

    return mul_traits::multiply(m1, m2);
}

}       //- STD_LA namespace
#endif  //- LINEAR_ALGEBRA_ARITHMETIC_OPERATORS_HPP_DEFINED