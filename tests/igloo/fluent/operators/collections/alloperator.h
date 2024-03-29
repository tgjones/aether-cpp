
//          Copyright Joakim Karlsson & Kim Gräsman 2010-2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef IGLOO_ALLOPERATOR_H
#define IGLOO_ALLOPERATOR_H

#include <igloo/fluent/operators/collections/collectionoperator.h>

namespace igloo {

   struct AllOperator : public CollectionOperator
   {
      template <typename ConstraintListType, typename ActualType>
      void Evaluate(ConstraintListType& list, ResultStack& result, OperatorStack& operators, const ActualType& actual)
      {
        unsigned int passed_elements = CollectionConstraintEvaluator<ConstraintListType, ActualType>::Evaluate(*this, list, result, operators, actual);

         result.push(passed_elements == actual.size());
      }
   };

   template<>
   struct Stringizer<AllOperator>
   {
      static std::string ToString(const AllOperator&)
      {
        return "all";
      }
   };
}

#endif
