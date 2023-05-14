export module OmniMatrices.Matrices;
import <array>;
import <memory>;

namespace OmniMatrices
{
	inline namespace Matrices
	{
		export using MatrixSize = unsigned;

		template <typename T>
		export concept MatrixElementC = true;

		template <MatricElementC Element, MatrixSize size>
		using Vector = std::array<Element, size>;
		

		//TODO: add operator functor as template args
		template
			< MatrixElementC Element_
			, MatrixSize columnNumber_
			, MatrixSize rowNumber_
			>
		export class Matrix final
		{
		public:
			//alias
			using Element = Element_;
			static constexpr MatrixSize columnNumber = columnNumber_;
			static constexpr MatrixSize rowNumber = rowNumber_;
		private:
			using This = Matrix<Element_, columnNumber_, rowNumber_>;
		private:
			std::unique_ptr<
				Vector<Vector<Element, columnNumber>, rowNumber>
			> mData;
		public:
			Matrix();
			Matrix(const This &);
			Matrix(This &&);

			~Matrix() = default;


			This & operator=(const This & another);
			This & operator=(This && another);

			[[nodiscard]]
			bool operator==(const This & another) const;

			[[nodiscard]]
			This operator*(const This & another) const;
			This & operator*=(const This & another);



			//getter and setter
			const Element & getElementAt
				( const MatrixSize rowNumber
				, const MatrixSize columnNumber
				) const;
			This & setElementAt
				( const MatrixSize rowNumber
				, const MatrixSize columnNumber
				) ;
			//TODO: add operator[]
		};


	}//namespace Matrices
}//namespace OmniMatrices
