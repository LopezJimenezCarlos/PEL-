 template<typename T>
   class Dynarray {
      T* p_;             // inicio del alojamiento
      std::size_t size_; // número de elementos a almacenar
   public:
      // construcción y destrucción:
      explicit Dynarray(std::size_t n) : p_{new T[n]}, size_{n} { }
      ~Dynarray() { delete[] p_; }
      
      // acceso a elementos (sin bound checking):
      auto operator[](std::size_t i) const -> T const& { return p_[i]; }
      auto operator[](std::size_t i)       -> T&       { return p_[i]; }
  
      // resto de la interfaz pública (operaciones de copia/movimiento, iteradores, etc)
   };
