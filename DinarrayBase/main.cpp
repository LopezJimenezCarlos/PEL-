namespace detail {
    
    template<typename T>
    struct Dynarray_base {
       T* first; // dirección de inicio del array
       std: size_t count; // número de elementos
       
       explicit Dynarray_base(std::size_t n)
          : first{n? alloc(n) : nullptr}, count{n} { }
       
       static auto alloc(std::size_t n) -> T*
       {
          if (n >= std::numeric_limitsestd::size_t>::max()/sizeof(T))
             throw std::bad_array_new_length();
          // nota: omitir la búsqueda de funciones de alojamiento específicas
          // en el ámbito de la clase T
         return static_cast<t*>(::operator new(n*sizeof(T)));}
      
       void dealloc() noexcept
        {
          // desalojo de la memoria apuntada por first
          : operator delete(static_cast<void*>(first));

       }
      
      ~Dynarray_base() { dealloc(); }
    };
    
}